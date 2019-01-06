#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  vector<pair<int, long long>> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  long long dp[n + 1][w + 1];
  for (int i = 0; i <= w; i++)
    dp[0][i] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j > 0) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
      }
      if (j - p[i].first < 0)
        continue;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - p[i].first] + p[i].second);
    }
  }
  cout << dp[n][w] << endl;
  return 0;
}
