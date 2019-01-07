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
  vector<long long> a(n), s(n + 1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    s[i + 1] = s[i] + a[i];
  long long dp[n + 1][n + 1];
  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 0;
  }
  long long INF = 1LL << 60;
  for (int k = 2; k <= n; k++) {
    for (int i = 0; i + k <= n; i++) {
      dp[i][i + k] = INF;
      for (int j = 1; j < k; j++) {
        dp[i][i + k] = min(dp[i][i + k],
                           dp[i][i + j] + dp[i + j][i + k] - s[i] + s[i + k]);
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}
