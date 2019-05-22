#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int costs[303][303] = {0};
int dp[303][303] = {0};

int f(string &s, string &t) {
  costs[0][0] = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      costs[i + 1][j + 1] = costs[i][j] + (s[i] == t[j]);
    }
  }
  for (int i = n; i >= 0; i--)
    for (int j = n; j >= 0; j--) {
      dp[i][j] = 10000000;
      if (i == n && j == n) dp[i][j] = 0;
      if (i < n) {
        dp[i][j] = min(dp[i][j], dp[i + 1][j] + costs[i + 1][j]);
      }
      if (j < n) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1] + costs[i][j + 1]);
      }
    }

  return dp[0][0];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> hw(h);
  vector<string> ss(w);
  for (int i = 0; i < h; i++) {
    cin >> hw[i];
    for (int j = 0; j < w; j++) {
      ss[j].push_back(hw[i][j]);
    }
  }
  // for (int i = 0; i < w; i++) reverse(ss[i].begin(), ss[i].end());
  int ans = 0;
  for (int i = 0; i < w - 1; i++) {
    ans += f(ss[i], ss[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
