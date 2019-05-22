#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[5050][5050] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end(), [](const pair<ll, ll> &l, const pair<ll, ll> &r) {
    if (l.first + l.second == r.first + r.second)
      return l.second < r.second;
    return l.first + l.second < r.first + r.second;
  });
  ll INF = 2000000000000000000LL;
  for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (dp[i][j] <= p[i].first) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + p[i].second);
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    if (dp[n][i] < INF) ans = i;
  }
  cout << ans << endl;
  return 0;
}
