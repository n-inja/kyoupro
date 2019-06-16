#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll n, m;
vector<ll> v, w;

ll P = 1000000007;
ll dp[2010][2010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  v.resize(n);
  w.resize(m);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < m; i++) cin >> w[i];

  ll ans = 1;
  dp[0][0] = 1;
  for (int i = 0; i <= m; i++) dp[0][i] = 1;
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + P) % P;
      if (v[i] == w[j]) {
        ans += dp[i][j];
        ans %= P;
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= P;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
