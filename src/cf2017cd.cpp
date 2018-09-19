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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(1 << 26), a(202020);
  for (int i = 0; i < (1 << 26); i++)
    dp[i] = n + 1;
  for (int i = 0; i < n; i++)
    a[i] ^= (1 << (s[i] - 'a'));
  for (int i = 1; i < n; i++)
    a[i] ^= a[i - 1];
  vector<int> opt(202020);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    opt[i + 1] = dp[a[i]] + 1;
    for (int j = 0; j < 26; j++) {
      opt[i + 1] = min(opt[i + 1], dp[a[i] ^ (1 << j)] + 1);
    }
    dp[a[i]] = min(dp[a[i]], opt[i + 1]);
  }
  cout << opt[n] << endl;
  return 0;
}
