#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[1 << 17] = {0};
ll sum[1 << 17] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<ll>> w(n, vector<ll>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> w[i][j];
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) for (int l = 0; l < n; l++) if ((i & (1 << j)) && (i & (1 << l))) sum[i] += w[j][l];
    sum[i] /= 2;
  }

  ll INF = 1 << 30;
  for (int i = 0; i < (1 << n); i++) dp[i] = -INF;

  int full = (1 << n) - 1;
  function<ll(int)> dfs;
  dfs = [&](int bit) {
    if (dp[bit] > -INF) return dp[bit];
    dp[bit] = -(sum[full] - sum[bit] - sum[full ^ bit]);
    dp[bit] += k;

    for (int i = bit; i >= 0; i--) {
      i &= bit;
      int j = i ^bit;
      if (i == 0 || j == 0) continue;
      ll s = sum[bit] - sum[i] - sum[j];

      dp[bit] = max(dp[bit], dfs(i) + dfs(j) + s);
    }
    return dp[bit];
  };

  cout << dfs((1 << n) - 1) << endl;
  return 0;
}
