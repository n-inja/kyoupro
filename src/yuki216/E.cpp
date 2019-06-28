#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll cost[20][20] = {0};
ll dp[1LL << 16][16] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cost[i][j] = -100000000;
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    cost[a][b] = max(cost[a][b], c);
    cost[b][a] = max(cost[b][a], c);
  }
  for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) dp[i][j] = -1000000;
  for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
  ll ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if ((i >> k) & 1) continue;
        ll next = i | (1 << k);
        dp[next][k] = max(dp[next][k], dp[i][j] + cost[j][k]);
        ans = max(ans, dp[next][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
