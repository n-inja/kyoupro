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
  int n;
  cin >> n;
  vector<int> a(2500);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<long long>> dp(2500), sdp(2500);
  for (int i = 0; i < 2500; i++) {
    dp[i].resize(2500);
    sdp[i].resize(2501);
  }
  for (int i = 0; i <= a[0]; i++) {
    dp[0][i] = 1;
  }
  for (int i = 0; i < 2500; i++) {
    if (i * 2 <= a[0])
      sdp[0][i + 1] = (sdp[0][i] + dp[0][i * 2]) % P;
    else
      sdp[0][i + 1] = sdp[0][i];
  }
  for (int i = 1; i < 2500; i++) {
    dp[i][0] = 1;
    for (int j = 1; j < 2500; j++) {
      dp[i][j] = sdp[i - 1][j + 1] - sdp[i - 1][max(0, j - a[i])];
      dp[i][j] %= P;
      dp[i][j] += P;
      dp[i][j] %= P;
    }
    for (int j = 0; j < 2500; j++) {
      if (j * 2 < 2500)
        sdp[i][j + 1] = (sdp[i][j] + dp[i][j * 2]) % P;
      else
        sdp[i][j + 1] = sdp[i][j];
    }
  }
  long long ans = 0;
  for (int i = 0; i < 2500; i++) {
    ans += dp[i][1];
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}
