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

#define P 1000000007

using namespace std;

// [iまで][1.size - 0.size最大値][最小値]の通り数
long long dp[301][305][305] = {0};

int main() {
  int n, K;
  cin >> n >> K;
  string s;
  cin >> s;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= K; k++) {
        if (s[i] == '1') {
          if (k > 0)
            dp[i + 1][j + 1][k - 1] =
                (dp[i + 1][j + 1][k - 1] + dp[i][j][k]) % P;
          else
            dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % P;
        } else if (s[i] == '0') {
          if (j > 0)
            dp[i + 1][j - 1][k + 1] =
                (dp[i + 1][j - 1][k + 1] + dp[i][j][k]) % P;
          else
            dp[i + 1][0][k + 1] = (dp[i + 1][0][k + 1] + dp[i][j][k]) % P;
        } else {
          if (k > 0)
            dp[i + 1][j + 1][k - 1] =
                (dp[i + 1][j + 1][k - 1] + dp[i][j][k]) % P;
          else
            dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % P;
          if (j > 0)
            dp[i + 1][j - 1][k + 1] =
                (dp[i + 1][j - 1][k + 1] + dp[i][j][k]) % P;
          else
            dp[i + 1][0][k + 1] = (dp[i + 1][0][k + 1] + dp[i][j][k]) % P;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= K; i++)
    for (int j = 0; j <= K; j++)
      ans = (ans + dp[n][i][j]) % P;
  cout << ans << endl;
  return 0;
}
