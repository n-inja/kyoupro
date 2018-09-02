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

using pll = pair<long long, long long>;
vector<vector<int>> path;
vector<int> x;

vector<pll> plls;

bool dfs(int i) {
  int n = path[i].size();
  if (n == 0) {
    plls[i].first = x[i];
    return true;
  }
  long long minSum = 0, maxSum = 0;
  vector<long long> diffs;
  for (int j = 0; j < n; j++) {
    if (!dfs(path[i][j]))
      return false;
    minSum += min(plls[path[i][j]].first, plls[path[i][j]].second);
    maxSum += max(plls[path[i][j]].first, plls[path[i][j]].second);
    diffs.push_back(abs(plls[path[i][j]].first - plls[path[i][j]].second));
  }
  if (minSum > x[i]) {
    return false;
  }
  int m = x[i] - minSum;
  vector<vector<bool>> dp(n + 1);
  for (int j = 0; j < n + 1; j++)
    dp[j].resize(m + 1);
  dp[0][0] = true;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      if (dp[i][j]) {
        dp[i + 1][j] = true;
        if (j + diffs[i] <= m) {
          dp[i + 1][j + diffs[i]] = true;
        }
      }
    }
  }
  for (int i = 0; i <= m; i++)
    if (dp[n][i])
      ans = i;
  plls[i].first = x[i];
  plls[i].second = maxSum - ans;
  return true;
}

int main() {
  int n;
  cin >> n;
  plls.resize(n);
  path.resize(n);
  x.resize(n);
  vector<int> p(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n - 1; i++)
    path[p[i] - 1].push_back(i + 1);
  if (dfs(0)) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
