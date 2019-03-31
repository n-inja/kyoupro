#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;
  vector<pair<long long, long long>> ab(n);
  for (int i = 0; i < n; i++)
    cin >> ab[i].first >> ab[i].second;
  sort(ab.begin(), ab.end(),
       [](const pair<long long, long long> &lhs,
          const pair<long long, long long> &rhs) {
         return lhs.first > rhs.first;
       });
  long long dp[n + 1][p + 1];
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < p + 1; j++)
      dp[i][j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < p + 1; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + ab[i].first <= p) {
        dp[i + 1][j + ab[i].first] =
            max(dp[i + 1][j + ab[i].first], dp[i][j] + ab[i].second);
      }
    }
  long long ans = dp[n][p];
  for (int i = 0; i < n + 1; i++) {
    for (int j = i; j < n; j++) {
      ans = max(ans, dp[i][p] + ab[j].second);
    }
  }
  cout << ans << endl;
  return 0;
}
