#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll dp[5001][5001] = {0};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vll a;
  int bef = 0;
  for (int i = 0; i < n; i++)
    if (bef != v[i]) {
      a.push_back(bef = v[i]);
    }
  int m = a.size();
  ll ans = n;
  dp[0][0] = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      if (a[i] == a[m - 1 - j])
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
    }
  for (int i = 0; i < m; i++) {
    ans = min(ans, m - 1 - dp[i][m - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}
