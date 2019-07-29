#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[2020][2020] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n), sum(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
  for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = -1;
  if (sum[n] == k) {
    cout << 1 << endl;
    return 0;
  }
  dp[0][0] = k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] < 0) continue;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (i == 0) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - 1);
        continue;
      }
      ll win = k - dp[i][j];
      ll s = sum[i];

      ll next = sum[i + 1];
      ll nwin = (win * next + s) / s - win;
      if (nwin > dp[i][j]) continue;
      if (nwin > a[i]) continue;
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - nwin);
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] >= 0) ans = max(ans, j);
    }
  }
  cout << ans << endl;
  return 0;
}