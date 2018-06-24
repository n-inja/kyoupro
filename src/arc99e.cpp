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
vector<vector<int>> path;
vector<int> col;

pair<int, bool> dfs(int id, int c) {
  if (col[id] < 0) {
    col[id] = c;
  } else if (col[id] != c) {
    return make_pair(0, true);
  } else
    return make_pair(0, false);
  pair<int, bool> ret(0, false);
  if (c == 0)
    ret.first++;
  else
    ret.first--;
  for (int i = 0; i < path[id].size(); i++) {
    pair<int, bool> r = dfs(path[id][i], 1 - c);
    if (r.second)
      return make_pair(0, true);
    ret.first += r.first;
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ab(m);
  for (int i = 0; i < m; i++) {
    cin >> ab[i].first >> ab[i].second;
    ab[i].first--;
    ab[i].second--;
  }
  bool p[1000][1000] = {0};
  for (int i = 0; i < m; i++)
    p[ab[i].first][ab[i].second] = p[ab[i].second][ab[i].first] = true;
  path.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || p[i][j])
        continue;
      path[i].push_back(j);
    }
  }
  col.resize(n);
  for (int i = 0; i < n; i++)
    col[i] = -1;
  vector<int> diffs;
  for (int i = 0; i < n; i++) {
    if (col[i] < 0) {
      pair<int, bool> ib = dfs(i, 0);
      if (ib.second) {
        cout << -1 << endl;
        return 0;
      }
      diffs.push_back(abs(ib.first));
    }
  }
  bool dp[1000][2001] = {0};
  int offset = 1000;
  dp[0][offset] = true;
  for (int i = 0; i < diffs.size(); i++) {
    for (int j = -800; j <= 800; j++) {
      if (dp[i][j + offset]) {
        dp[i + 1][j + offset + diffs[i]] = true;
        dp[i + 1][j + offset - diffs[i]] = true;
      }
    }
  }
  int ans = m;
  for (int i = -800; i <= 800; i++) {
    if (dp[diffs.size()][i + offset]) {
      int size = (n - abs(i)) / 2;
      int sub = n - size;
      ans = min(ans, size * (size - 1) / 2 + sub * (sub - 1) / 2);
    }
  }
  cout << ans << endl;
  return 0;
}
