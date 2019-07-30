#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n;
vector<string> mp;
ll dp[51][51][51][51] = {0};
ll sum[51][51] = {0};

ll dfs(int y, int x, int h, int w) {
  if (dp[y][x][h][w] >= 0) return dp[y][x][h][w];
  if (w == 0 || h == 0) return dp[y][x][h][w] = 0;
  if (sum[y + h][x + w] - sum[y][x + w] - sum[y + h][x] + sum[y][x] == 0) {
    return dp[y][x][h][w] = 0;
  }
  dp[y][x][h][w] = max(h, w);
  for (int h2 = 1; h2 < h; h2++) {
    dp[y][x][h][w] = min(dp[y][x][h][w], dfs(y, x, h2, w) + dfs(y + h2, x, h - h2, w));
  }
  for (int w2 = 1; w2 < w; w2++) {
    dp[y][x][h][w] = min(dp[y][x][h][w], dfs(y, x, h, w2) + dfs(y, x + w2, h, w - w2));
  }
  return dp[y][x][h][w];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  mp.resize(n);
  for (int i = 0; i < n; i++) cin >> mp[i];


  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (mp[i][j] == '#' ? 1 : 0);
    }

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        for (int l = 0; l <= n; l++)
          dp[i][j][k][l] = -1;
  cout << dfs(0, 0, n, n) << endl;

  return 0;
}
