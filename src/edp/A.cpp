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
  int n;
  cin >> n;
  vector<long long> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  long long dp[n + 2];
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < n; i++) {
    dp[i] =
        min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
  }
  cout << dp[n - 1] << endl;
  return 0;
}
