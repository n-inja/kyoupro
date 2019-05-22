#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int dp[303][303][303] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  int k;
  cin >> s >> k;
  string t = s;
  reverse(t.begin(), t.end());

  int n = s.size();

  for (int i = 0; i < n; i++) dp[i][i + 1][0] = 1;

  for (int d = 2; d <= n; d++) {
    for (int i = 0; i < n; i++) {
      int j = d + i;
      if (j > n) continue;
      for (int l = 0; l <= k; l++) {
        dp[i][j][l] = max(dp[i + 1][j][l], dp[i][j - 1][l]);
        if (s[i] == s[j - 1]) {
          dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l] + 2);
        } else {
          if (l > 0)
            dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l - 1] + 2);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= k; i++) ans = max(ans, dp[0][n][i]);
  cout << ans << endl;

  return 0;
}
