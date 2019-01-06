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
  vector<long long> act[3];
  act[0].resize(n);
  act[1].resize(n);
  act[2].resize(n);
  for (int i = 0; i < n; i++)
    cin >> act[0][i] >> act[1][i] >> act[2][i];

  long long dp[n + 1][3];
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        if (j == k)
          continue;
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + act[j][i - 1]);
      }
    }
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
  return 0;
}
