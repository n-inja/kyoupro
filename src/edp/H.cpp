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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++)
    cin >> s[i];
  long long dp[h][w];
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == 0 && j == 0)
        continue;
      dp[i][j] = 0;
      if (s[i][j] == '#')
        continue;
      if (i > 0)
        dp[i][j] += dp[i - 1][j];
      if (j > 0)
        dp[i][j] += dp[i][j - 1];
      dp[i][j] %= P;
    }
  }
  cout << dp[h - 1][w - 1] << endl;
  return 0;
}
