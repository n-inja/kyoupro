#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

#define P 1000000007

using namespace std;

int main() {
  int n, w, k;
  cin >> w >> n >> k;
  vector<pair<int, int>> c(n);
  for(int i = 0; i < n; i++) cin >> c[i].first >> c[i].second;
  vector<vector<vector<int>>> dp(w + 1);
  for(int i = 0; i < w + 1; i++) {
    dp[i].resize(n + 1);
    for(int j = 0; j < n + 1; j++) {
      dp[i][j].resize(k + 1);
    }
  }
  for(int i = 1; i < w + 1; i++) {
    for(int j = 1; j < n + 1; j++) {
      for(int l = 1; l < k + 1; l++) {
        dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j - 1][l]);
        if(i >= c[j - 1].first) {
          dp[i][j][l] = max(dp[i][j][l], dp[i - c[j - 1].first][j - 1][l - 1] + c[j - 1].second);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < k + 1; i++) {
    ans = max(ans, dp[w][n][i]);
  }
  cout << ans << endl;
  return 0;
}
