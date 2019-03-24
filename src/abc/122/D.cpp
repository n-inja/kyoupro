#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll dp[300][4][4][4] = {0};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  "AGCT";
  ll P = 1000000007;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) {
        if ((i == 0 && j == 1 && k == 2) || (i == 0 && j == 2 && k == 1) ||
            (i == 1 && j == 0 && k == 2))
          continue;
        dp[3][i][j][k] = 1;
      }
  for (int id = 3; id < n; id++) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
          for (int l = 0; l < 4; l++) {
            if ((j == 0 && k == 1 && l == 2) || (j == 0 && k == 2 && l == 1) ||
                (j == 1 && k == 0 && l == 2))
              continue;
            if ((i == 0 && j == 1 && l == 2) || (i == 0 && k == 1 && l == 2))
              continue;
            dp[id + 1][j][k][l] += dp[id][i][j][k];
            dp[id + 1][j][k][l] %= P;
          }
  }
  ll ans = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) {
        ans += dp[n][i][j][k];
        ans %= P;
      }
  cout << ans << endl;
  return 0;
}
