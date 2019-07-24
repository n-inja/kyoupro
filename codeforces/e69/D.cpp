#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[302020][11] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  ll INF = 1010101010010;
  ll ans = 0;
  for (int i = 0; i <= n; i++) for (int j = 0; j < m; j++) dp[i][j] = -INF;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) dp[0][i] = -k;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = max(a[i] - k, dp[i][m - 1] + a[i] - k);
    ans = max(ans, dp[i + 1][0]);
    for (int j = 1; j < m; j++) {
      dp[i + 1][j] = max(dp[i][j - 1] + a[i], a[i] - k);
      ans = max(ans, dp[i + 1][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
