#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  int x, y, z, n;
  cin >> x >> y >> n;
  z = x + y;
  vector<pair<int, long long>> ths(n);
  for (int i = 0; i < n; i++)
    cin >> ths[i].first >> ths[i].second;
  long long dp[n + 1][z + 1];
  long long dp2[n + 1][z + 1];
  for (int j = 0; j < n + 1; j++)
    for (int k = 0; k < z + 1; k++)
      dp[j][k] = dp2[j][k] = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < z + 1; k++) {
        dp2[j + 1][k] = dp[j + 1][k];
        if (k - ths[i].first + 1 >= 0)
          dp2[j + 1][k] =
              max(dp[j][k - ths[i].first + 1] + ths[i].second, dp2[j + 1][k]);
        if (k + j + 1 <= z && j + 1 <= x) {
          ans = max(ans, dp2[j + 1][k]);
        }
      }
    }
    for (int j = 0; j < n + 1; j++)
      for (int k = 0; k < z + 1; k++)
        dp[j][k] = dp2[j][k];
  }
  cout << ans << endl;
  return 0;
}
