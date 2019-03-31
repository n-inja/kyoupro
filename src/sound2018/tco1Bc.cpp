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

class ThreeSameLetters {
public:
  long long P = 1000000007;
  ThreeSameLetters() {}
  // l length, s charactors
  int countStrings(int l, int s) {
    int ans = 0;
    if (l <= 2)
      return 0;
    // dp[has block][leng][last - 1][last]
    long long dp[2][27][27][27] = {0};
    for (int i = 1; i <= s; i++)
      for (int j = 1; j <= s; j++)
        dp[0][2][i][j] = 1;
    for (int i = 0; i < 2; i++) {
      for (int j = 2; j < l; j++) {
        for (int c1 = 1; c1 <= s; c1++) {
          for (int c2 = 1; c2 <= s; c2++) {
            if (i == 1) {
              if (c1 == c2) {
                for (int k = 1; k <= s; k++) {
                  if (k == c2)
                    continue;
                  else
                    dp[1][j + 1][c2][k] =
                        (dp[1][j + 1][c2][k] + dp[i][j][c1][c2]) % P;
                }
              } else {
                for (int k = 1; k <= s; k++)
                  dp[1][j + 1][c2][k] =
                      (dp[1][j + 1][c2][k] + dp[i][j][c1][c2]) % P;
              }
            } else {
              if (c1 == c2) {
                for (int k = 1; k <= s; k++) {
                  if (k == c2)
                    dp[1][j + 1][c2][k] =
                        (dp[1][j + 1][c2][k] + dp[i][j][c1][c2]) % P;
                  else
                    dp[0][j + 1][c2][k] =
                        (dp[0][j + 1][c2][k] + dp[i][j][c1][c2]) % P;
                }
              } else {
                for (int k = 1; k <= s; k++)
                  dp[0][j + 1][c2][k] =
                      (dp[0][j + 1][c2][k] + dp[i][j][c1][c2]) % P;
              }
            }
          }
        }
      }
    }
    for (int i = 1; i <= s; i++)
      for (int j = 1; j <= s; j++)
        ans = (ans + dp[1][l][i][j]) % P;
    return ans;
  }
};

int main() {
  ThreeSameLetters t;
  cout << t.countStrings(10, 11) << endl;
  return 0;
}
