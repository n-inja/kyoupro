#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string rgb = "RGB";
  int inv[256] = {0};
  inv['R'] = 0;
  inv['G'] = 1;
  inv['B'] = 2;
  int dp[n + 1][3], from[n + 1][3];
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  from[0][0] = from[0][1] = from[0][2] = -1;
  dp[1][0] = dp[1][1] = dp[1][2] = 1;
  from[1][0] = -1;
  from[1][1] = -1;
  from[1][2] = -1;
  dp[1][inv[s[0]]] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < 3; j++)
      dp[i][j] = n + 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k)
          continue;
        if (dp[i][j] + ((inv[s[i]] == k) ? 0 : 1) < dp[i + 1][k]) {
          dp[i + 1][k] = dp[i][j] + ((inv[s[i]] == k) ? 0 : 1);
          from[i + 1][k] = j;
        }
      }
    }
  }
  string ans;
  int now = n;
  int l = 0;
  for (int i = 1; i < 3; i++) {
    if (dp[n][l] > dp[n][i])
      l = i;
  }
  cout << dp[n][l] << endl;
  ans.push_back(rgb[l]);
  for (; from[now][l] >= 0; now--) {
    ans.push_back(rgb[from[now][l]]);
    l = from[now][l];
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
