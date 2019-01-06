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
  long long P = 1000000007;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long dp[n + 1][k + 1], sdp[n + 1][k + 2];
  for (int i = 0; i <= k; i++)
    dp[0][i] = sdp[0][i] = 0;
  sdp[0][k + 1] = 0;
  sdp[0][0] = 0;
  sdp[0][1] = dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    sdp[i][0] = 0;
    for (int j = 1; j <= k + 1; j++) {
      sdp[i][j] = (sdp[i][j - 1] + dp[i][j - 1]) % P;
    }
    for (int j = 0; j <= k; j++) {
      dp[i + 1][j] = (sdp[i][j + 1] - sdp[i][max(0, j - a[i])] + P) % P;
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
