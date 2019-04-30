#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[400][400] = {0};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      dp[i][j] = -1;
  // dp[i][j] := i日目にj回をちょうどしたときの最大
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] < 0)
        continue;
      for (int l = 0; l < k; l++) {
        if (i + l < n)
          dp[i + l + 1][j + 1] = max(dp[i + l + 1][j + 1], dp[i][j] + a[i + l]);
      }
    }
  }
  ll ans = -1;
  for (int i = n - k + 1; i <= n; i++)
    ans = max(ans, dp[i][m]);
  cout << ans << endl;
  return 0;
}
