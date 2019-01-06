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
  string s, t;
  cin >> s >> t;
  long long dp[s.size() + 1][t.size() + 1];
  for (int i = 0; i <= s.size(); i++)
    dp[i][0] = 0;
  for (int j = 0; j <= t.size(); j++)
    dp[0][j] = 0;
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < t.size(); j++) {
      dp[i + 1][j + 1] = 0;
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i][j + 1], dp[i + 1][j]));
    }
  string ans;
  int i = s.size(), j = t.size();
  while (i > 0 && j > 0 && dp[i][j] > 0) {
    if (dp[i][j] == dp[i - 1][j - 1] + 1 && dp[i][j] == dp[i - 1][j] + 1 &&
        dp[i][j] == dp[i][j - 1] + 1) {
      ans.push_back(s[i - 1]);
      i--;
      j--;
      continue;
    }
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
      continue;
    } else {
      j--;
      continue;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
