#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int n;
vector<vector<int>> p;
vector<map<int, int>> memo;

int dfs(int i, int j) {
  if (memo[i][j] > 0)
    return memo[i][j];
  if (p[i].size() == 1)
    return memo[i][j] = 1;
  memo[i][j] = 1;
  for (int k = 0; k < p[i].size(); k++) {
    if (j == p[i][k])
      continue;
    memo[i][j] += dfs(p[i][k], i);
  }
  return memo[i][j];
}

int solve(int i) {
  int ret = 0;
  if (p[i].size() == 1) {
    return n - 1;
  }
  for (int j = 0; j < p[i].size(); j++) {
    ret = max(ret, dfs(p[i][j], i));
  }
  return ret;
}

int main() {
  cin >> n;
  p.resize(n);
  memo.resize(n);
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    p[a].push_back(i);
    p[i].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    cout << solve(i) << endl;
  }

  return 0;
}
