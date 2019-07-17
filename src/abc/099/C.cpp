#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[101][101010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> v;
  v.push_back(1);
  for (ll i = 6; i <= n; i *= 6) v.push_back(i);
  for (ll i = 9; i <= n; i *= 9) v.push_back(i);
  int m = v.size();

  ll INF = 10000000000;
  for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[j][i] = INF;
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (j + v[i] <= n) {
        dp[i][j + v[i]] = min(dp[i][j + v[i]], dp[i][j] + 1);
      }
    }
  }
  cout << dp[m][n] << endl;
  return 0;
}
