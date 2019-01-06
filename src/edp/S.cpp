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
  string s;
  long long P = 1000000007;
  cin >> s;
  int d;
  cin >> d;
  if (s == "0") {
    cout << 0 << endl;
    return 0;
  }
  int n = s.size();
  long long dp[n + 1][d][10], sdp[n + 1][d];
  for (int i = 0; i < d; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k <= n; k++)
        dp[k][i][j] = 0;
  dp[0][0][0] = 1;

  for (int i = 0; i < d; i++)
    sdp[0][i] = 0;
  sdp[0][0] = 1;
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      for (int k = 0; k < 10; k++) {
        dp[i + 1][j][k] = 0;
        for (int l = 0; l < 10; l++) {
          dp[i + 1][j][k] += dp[i][((j - k) % d + d) % d][l];
          dp[i + 1][j][k] %= P;
        }
      }
      sdp[i + 1][j] = sdp[i][((j - (s[i] - '0')) % d + d) % d];
      for (int k = 0; i > 0 && k < s[i - 1] - '0'; k++) {
        sdp[i + 1][j] += dp[i][((j - (s[i] - '0')) % d + d) % d][k];
        sdp[i + 1][j] %= P;
      }
    }
  }
  long long ans = sdp[n][0];

  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      for (int j = 1; j < s[i] - '0'; j++) {
        ans += dp[i + 1][0][j];
        ans %= P;
      }
    } else {
      for (int j = 1; j < 10; j++) {
        ans += dp[i + 1][0][j];
        ans %= P;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
