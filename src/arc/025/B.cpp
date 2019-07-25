#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[101][101] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> mp(h, vector<int>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> mp[i][j];
      if (i % 2 == j % 2) mp[i][j] = -mp[i][j];
    }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dp[i + 1][j + 1] = dp[i + 1][j] - dp[i][j] + dp[i][j + 1] + mp[i][j];
    }
  }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      for (int k = 1; i + k <= h; k++)
        for (int l = 1; j + l <= w; l++) {
          if (dp[i + k][j + l] - dp[i + k][j] - dp[i][j + l] + dp[i][j] == 0) {
            ans = max(ans, k * l);
          }
        }
    }
  cout << ans << endl;
  return 0;
}
