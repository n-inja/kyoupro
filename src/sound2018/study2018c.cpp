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
vector<bool> ch;

bool dfs(int i, int from) {
  if (ch[i])
    return false;
  ch[i] = true;
  bool ret = true;
  for (int j = 0; j < path[i].size(); j++) {
    if (from == path[i][j])
      continue;
    if (!dfs(path[i][j], i))
      ret = false;
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ps(m);
  for (int i = 0; i < m; i++)
    cin >> ps[i].first >> ps[i].second;
  for (int i = 0; i < m; i++) {
    ps[i].first--;
    ps[i].second--;
  }
  path.resize(n);
  ch.resize(n);
  for (int i = 0; i < m; i++) {
    path[ps[i].first].push_back(ps[i].second);
    path[ps[i].second].push_back(ps[i].first);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dfs(i, -1))
      ans++;
  }
  cout << ans << endl;

  return 0;
}
