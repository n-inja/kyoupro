#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using pll = pair<ll, ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  map<pll, ll> mp;
  for (ll k = a; k <= b; k++) {
    vector<vector<pll>> dp(n + 1, vector<pll>(k + 1));
    dp[0][0] = make_pair(0, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (dp[i + 1][j].first == dp[i][j].first) {
          dp[i + 1][j].second += dp[i][j].second;
        }
        if (dp[i + 1][j].first < dp[i][j].first) {
          dp[i + 1][j] = dp[i][j];
        }
        if (j < k) {
          if (dp[i + 1][j + 1].first == dp[i][j].first + v[i]) {
            dp[i + 1][j + 1].second += dp[i][j].second;
          }
          if (dp[i + 1][j + 1].first < dp[i][j].first + v[i]) {
            dp[i + 1][j + 1].first = dp[i][j].first + v[i];
            dp[i + 1][j + 1].second = dp[i][j].second;
          }

        }
      }
    }
    ll g = __gcd(k, dp[n][k].first);
    mp[make_pair(dp[n][k].first / g, k / g)] += dp[n][k].second;
  }
  ll mx = 0;
  double ans = 0.;
  for (auto &pr : mp) {
    if (pr.first.first >= ans * pr.first.second) {
      ans = (double) pr.first.first / pr.first.second;
      mx = pr.second;
    }
  }
  printf("%.9lf\n%lld\n", ans, mx);

  return 0;
}
