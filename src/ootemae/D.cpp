#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;
ll dp[1010][1010][15] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(m);
  vector<int> v(m);
  for (int i = 0; i < m; i++) cin >> s[i];
  for (int i = 0; i < m; i++) v[i] = (s[i] == "FizzBuzz") ? 0 : (s[i] == "Fizz" ? 1 : 2);
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k < 15; k++) {
        if (dp[i][j][k] == 0) continue;
        if (m - j > n - i) {
          j = -n + i + m - 1;
          continue;
        }
        for (int l = 0; l < 10; l++) {
          if (i == 0 && l == 0) continue;
          int next = ((k * 10) + l) % 15;
          if (next == 0) {
            if (j >= m || v[j] != 0) continue;
            dp[i + 1][j + 1][next] += dp[i][j][k];
            dp[i + 1][j + 1][next] %= P;
          } else if (next % 3 == 0 && next % 5 != 0) {
            if (j >= m || v[j] != 1) continue;
            dp[i + 1][j + 1][next] += dp[i][j][k];
            dp[i + 1][j + 1][next] %= P;
          } else if (next % 5 == 0 && next % 3 != 0) {
            if (j >= m || v[j] != 2) continue;
            dp[i + 1][j + 1][next] += dp[i][j][k];
            dp[i + 1][j + 1][next] %= P;
          } else {
            dp[i + 1][j][next] += dp[i][j][k];
            dp[i + 1][j][next] %= P;
          }
        }
      }
  ll ans = 0;
  for (int i = 0; i < 15; i++) ans = (ans + dp[n][m][i]) % P;
  cout << ans << endl;
  return 0;
}
