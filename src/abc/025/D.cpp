#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

map<int, int> ocp;

int f(int y, int x) {
  return 1 << (y * 5 + x);
}

pair<int, int> inv(int bit) {
  return make_pair((31 - __builtin_clz(bit)) / 5, (31 - __builtin_clz(bit)) % 5);
}

bool check(int bit, int i, int sbit) {
  if (bit & sbit) return false;

  auto xy = inv(sbit);
  vector<int> bs(5);
  if (xy.first > 1)
    bs[0] = (bit & f(xy.first - 2, xy.second)) > 0;
  else
    bs[0] = -1;
  if (xy.first > 0)
    bs[1] = (bit & f(xy.first - 1, xy.second)) > 0;
  else
    bs[1] = -1;
  if (xy.first < 4)
    bs[3] = (bit & f(xy.first + 1, xy.second)) > 0;
  else
    bs[3] = -1;
  if (xy.first < 3)
    bs[4] = (bit & f(xy.first + 2, xy.second)) > 0;
  else
    bs[4] = -1;

//  if ((bs[0] == 1 && bs[1] == 1) || (bs[3] == 1 && bs[4] == 1)) return false;
  if ((bs[1] == 1 && bs[3] == 0) || (bs[3] == 1 && bs[1] == 0)) return false;

  if (xy.second > 1)
    bs[0] = (bit & f(xy.first, xy.second - 2)) > 0;
  else
    bs[0] = -1;
  if (xy.second > 0)
    bs[1] = (bit & f(xy.first, xy.second - 1)) > 0;
  else
    bs[1] = -1;
  if (xy.second < 4)
    bs[3] = (bit & f(xy.first, xy.second + 1)) > 0;
  else
    bs[3] = -1;
  if (xy.second < 3)
    bs[4] = (bit & f(xy.first, xy.second + 2)) > 0;
  else
    bs[4] = -1;

//  if ((bs[0] == 1 && bs[1] == 1) || (bs[3] == 1 && bs[4] == 1)) return false;
  if ((bs[1] == 1 && bs[3] == 0) || (bs[3] == 1 && bs[1] == 0)) return false;

  return true;
}

ll dp[1 << 25] = {0};
ll P = 1000000007;
vector<bool> used(25);

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<vector<int>> s(5, vector<int>(5));
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      cin >> s[i][j];
      if (s[i][j]) {
        ocp[s[i][j] - 1] = f(i, j);
        used[i * 5 + j] = true;
      }
    }

  dp[0] = 1;
  for (int i = 0; i < (1 << 25); i++) {
    if (!dp[i]) continue;
    int c = __builtin_popcount(i);
    if (ocp.find(c) != ocp.end()) {
      if (check(i, c, ocp[c])) {
        dp[i | ocp[c]] += dp[i];
        dp[i | ocp[c]] %= P;
      }
    } else {
      for (int j = 1; j < (1 << 25); j <<= 1) {
        auto yx = inv(j);
        if (used[yx.first * 5 + yx.second]) continue;
        if (check(i, c, j)) {
          dp[i | j] += dp[i];
          dp[i | j] %= P;
        }
      }
    }
  }
  cout << dp[(1 << 25) - 1] << endl;

  return 0;
}
