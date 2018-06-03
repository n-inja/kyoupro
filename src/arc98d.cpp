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
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<set<int>> bits(20);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 20; k++)
      if (a[i] & (1 << k))
        bits[k].insert(i);
  }
  vector<int> left(n);
  left[0] = 0;
  for (int i = 1; i < n; i++) {
    int maxL = -1;
    for (int k = 0; k < 20; k++) {
      if (a[i] & (1 << k)) {
        auto it = bits[k].find(i);
        if (it == bits[k].begin())
          continue;
        it--;
        maxL = max(maxL, *it);
      }
    }
    left[i] = maxL + 1;
  }
  long long ans = 0;
  vector<int> dp(n);
  dp[0] = 0;
  ans += dp[0] + 1;
  for (int i = 1; i < n; i++) {
    dp[i] = max(left[i], dp[i - 1]);
    ans += (i - dp[i]) + 1;
  }
  cout << ans << endl;
  return 0;
}
