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

class BIT {
public:
  int n;
  vector<int> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  void add(int a, int w) {
    a += 1;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }
  int sum(int a) {
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  int n;
  cin >> n;
  vector<pair<char, int>> ca(n * 2);
  for (int i = 0; i < n * 2; i++)
    cin >> ca[i].first >> ca[i].second;
  vector<vector<int>> dp(2001);
  for (int i = 0; i < 2001; i++)
    dp[i].resize(2001);
  vector<int> binv(n), winv(n);
  for (int i = 0; i < n * 2; i++)
    if (ca[i].first == 'B')
      binv[ca[i].second - 1] = i;
    else
      winv[ca[i].second - 1] = i;
  BIT white(1 << 13), black(1 << 13);
  for (int i = 0; i < n * 2; i++) {
    if (ca[i].first == 'B')
      black.add(i, 1);
    else
      white.add(i, 1);
  }
  for (int i = 0; i <= n; i++) {
    BIT moved(1 << 13), moved2(1 << 13);
    for (int j = 0; j < i - 1; j++) {
      moved.add(winv[j], 1);
      moved2.add(winv[j], 1);
    }
    if (i == 0) {
      for (int j = 0; j < n; j++) {
        if (j == 0) {
          dp[0][1] =
              black.sum(binv[0]) + white.sum(binv[0]) - moved.sum(binv[0]);
          moved.add(binv[0], 1);
          continue;
        }
        dp[0][j + 1] = dp[0][j] + black.sum(binv[j]) + white.sum(binv[j]) -
                       moved.sum(binv[j]);
        moved.add(binv[j], 1);
        continue;
      }
    } else {
      for (int j = 0; j <= n; j++) {
        if (j == 0) {
          dp[i][j] = dp[i - 1][j] + black.sum(winv[i - 1]) +
                     white.sum(winv[i - 1]) - moved.sum(winv[i - 1]);
          continue;
        }
        moved.add(binv[j - 1], 1);
        dp[i][j] = dp[i - 1][j] + black.sum(winv[i - 1]) +
                   white.sum(winv[i - 1]) - moved.sum(winv[i - 1]);
      }
      moved2.add(winv[i - 1], 1);
      for (int j = 0; j < n; j++) {
        dp[i][j + 1] =
            min(dp[i][j + 1], dp[i][j] + black.sum(binv[j]) +
                                  white.sum(binv[j]) - moved2.sum(binv[j]));
        moved2.add(binv[j], 1);
      }
    }
  }
  cout << dp[n][n] << endl;

  return 0;
}
