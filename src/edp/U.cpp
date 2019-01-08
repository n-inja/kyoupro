#include <algorithm>
#include <bitset>
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

bool has(int n, int k) { return (n >> k) & 1; }

int main() {
  int n;
  cin >> n;
  long long bit = 1 << n;
  vector<vector<long long>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  }
  long long sdp[bit];

  sdp[0] = 0;
  for (int i = 1; i < bit; i++) {
    sdp[i] = -10000000000000000LL;
    for (int j = 0; j < n; j++) {
      if (!has(i, j))
        continue;
      long long mask = i ^ (1 << j);
      long long tmp = 0;
      for (int k = 0; k < n; k++) {
        if (has(mask, k))
          tmp += a[j][k];
      }
      sdp[i] = max(sdp[i], sdp[mask] + tmp);
    }
  }

  long long dp[bit];
  dp[0] = 0;
  for (int i = 1; i < bit; i++) {
    dp[i] = sdp[i];
    long long sub = i;
    do {
      dp[i] = max(dp[i], dp[i - sub] + dp[sub]);
      sub = (sub - 1) & i;
    } while (sub);
  }
  cout << dp[bit - 1] << endl;
  return 0;
}
