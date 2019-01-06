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
  long long dp[n + 1][n * 1000 + 1];
  long long INF = 1000000000000000000LL;
  for (int i = 0; i <= n * 1000; i++)
    dp[0][i] = INF;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n * 1000; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j - p[i].second < 0)
        continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - p[i].second] + p[i].first);
    }
  }

  long long ans = 0;
  for (long long i = 0; i <= n * 1000; i++) {
    if (dp[n][i] <= w) {
      ans = max(ans, i);
    }
  }
  cout << ans << endl;
  return 0;
}
