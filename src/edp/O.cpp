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

long long dp[22][1 << 21] = {0};
int main() {
  long long P = 1000000007;
  int n;
  cin >> n;
  vector<vector<long long>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  }
  long long bit = 1 << n;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < bit; j++) {
      if (!dp[i][j])
        continue;
      for (int k = 0; k < n; k++) {
        if (!((j >> k) & 1) && a[i][k]) {
          dp[i + 1][j | (1 << k)] += dp[i][j];
          dp[i + 1][j | (1 << k)] %= P;
        }
      }
    }
  }
  cout << dp[n][bit - 1] << endl;
  return 0;
}
