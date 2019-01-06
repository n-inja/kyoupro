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
  int n;
  cin >> n;
  vector<double> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  double dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++)
    dp[i][0] = dp[0][i] = 0.;
  dp[0][0] = 1.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j > i) {
        dp[i][j] = 0.0;
        continue;
      }
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j] * (1 - p[i - 1]) + dp[i - 1][j - 1] * p[i - 1];
      }
    }
  }
  double ans = 0.0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    ans += dp[n][i];
  }
  printf("%.9lf\n", ans);
  return 0;
}
