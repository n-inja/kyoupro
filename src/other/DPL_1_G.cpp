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
  int n, w;
  cin >> n >> w;
  vector<long long> dp(w + 1);
  vector<pair<long long, long long>> ps(n);
  vector<int> m(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second >> m[i];
  }
  for (int i = 0; i < n; i++)
    for (int k = 0; m[i] > 0; k++) {
      long long key = min(m[i], (int)(1 << k));
      m[i] -= key;
      for (int j = w; j >= 0; j--) {
        if (j + ps[i].second * key <= w) {
          dp[j + ps[i].second * key] =
              max(dp[j + ps[i].second * key], dp[j] + ps[i].first * key);
        }
      }
    }
  long long ans = 0;
  for (int i = 0; i <= w; i++)
    ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
