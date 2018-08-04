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

class LeftToRightGame {
public:
  LeftToRightGame() {}
  int p(int b, int i, int d) {
    if (i == 0)
      return 1;
    if (i == 1)
      return b;
    if (i % 2 == 0)
      return p((b * b) % d, i / 2, d);
    return (b * p(b, i - 1, d)) % d;
  }
  int p(int i, int d) { return p(10, i, d); }
  int sub(int a, int b, int d) { return ((a - b) % d + d) % d; }
  string whoWins(int l, int d) {
    bool dp[1001][1001];
    for (int i = 0; i <= l; i++)
      for (int j = 0; j < d; j++)
        dp[i][j] = false;
    dp[0][0] = true;
    for (int i = 1; i < d; i++)
      dp[0][i] = false;
    for (int i = 1; i <= l; i++) {
      int power = p(i - 1, d);
      int small = 0;
      if (i == l)
        small = 1;
      for (int j = 0; j < d; j++) {
        if ((l + i) % 2 == 1) {
          // Bob
          dp[i][j] = false;
          for (int k = small; k < 10; k++) {
            if (dp[i - 1][sub(j, (k * power) % d, d)])
              dp[i][j] = true;
          }
        } else {
          // Alice
          dp[i][j] = true;
          for (int k = small; k < 10; k++) {
            if (!dp[i - 1][sub(j, (k * power) % d, d)])
              dp[i][j] = false;
          }
        }
      }
    }
    return dp[l][0] ? "Bob" : "Alice";
  }
};

int main() {
  LeftToRightGame l;
  cout << l.whoWins(4, 11) << endl;
  return 0;
}
