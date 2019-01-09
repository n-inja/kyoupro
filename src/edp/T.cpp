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
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = 0;
  for (int i = 0; i < n; i++)
    dp[0][i] = 1;
  for (int i = 0; i < n - 1; i++) {
    long long sdp[30303] = {0};
    sdp[0] = 0;
    for (int j = 0; j < n; j++) {
      sdp[j + 1] = (sdp[j] + dp[i][j]) % P;
    }
    for (int j = 0; j < n - i - 1; j++) {
      if (s[i] == '<') {
        dp[i + 1][j] = (sdp[n] - sdp[j + 1] + P) % P;
      } else {
        dp[i + 1][j] = sdp[j + 1];
      }
    }
  }
  cout << dp[n - 1][0] << endl;
  return 0;
}
