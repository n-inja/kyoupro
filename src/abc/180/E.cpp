#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll INF = 1LL << 62;
struct P {
  long long x, y, z;
};
vector<P> ps;

long long dst(int i, int j) {
  return abs(ps[i].x - ps[j].x) + abs(ps[i].y - ps[j].y) + max(0LL, ps[j].z - ps[i].z);
}

ll dp[1 << 18][18] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  ps.resize(n);
  for (int i = 0; i < n; i++) cin >> ps[i].x >> ps[i].y >> ps[i].z;
  ll all_bit = 1 << n;
  for (int i = 0; i < all_bit; i++) for (int j = 0; j < n; j++) dp[i][j] = INF;
  for (int i = 1; i < n; i++) {
    dp[1 << i][i] = dst(0, i);
  }
  for (int i = 1; i < all_bit; i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) continue;
      int next = i | (1 << j);
      for (int k = 0; k < n; k++) {
        if ((i & (1 << k)) == 0) continue;
        ll d = dp[i][k] + dst(k, j);
        dp[next][j] = min(dp[next][j], d);
      }
    }
  }
  cout << dp[all_bit - 1][0] << endl;
  return 0;
}
