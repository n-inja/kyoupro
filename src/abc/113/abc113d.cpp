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

long long P = 1000000007;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  // dp[位置][段目] := 1から辿ってそこにいけるような構成数
  long long dp[102][8] = {0};
  // dp2[i] := i番目で終わってるあみだ
  long long dp2[10] = {0}, sumdp2[11] = {0};
  sumdp2[1] = dp2[0] = 1;
  dp2[1] = 0;
  sumdp2[2] = 1;
  for (int i = 2; i < 10; i++) {
    dp2[i] = sumdp2[i - 1];
    sumdp2[i + 1] = sumdp2[i] + dp2[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dp[i + 1][j] += (dp[i][j] * ((sumdp2[j + 1] * sumdp2[w - j]) % P)) % P;
      dp[i + 1][j] %= P;
      if (j > 0) {
        dp[i + 1][j - 1] += (dp[i][j] * ((sumdp2[j] * sumdp2[w - j]) % P)) % P;
        dp[i + 1][j - 1] %= P;
      }
      if (j < w - 1) {
        dp[i + 1][j + 1] +=
            (dp[i][j] * ((sumdp2[j + 1] * sumdp2[w - j - 1]) % P)) % P;
        dp[i + 1][j + 1] %= P;
      }
    }
  }
  cout << dp[h][k - 1] << endl;
  return 0;
}
