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
int n, m, x;
vector<bool> used;
vector<long long> solved;
vector<pair<int, long long>> c;
vector<vector<pair<int, long long>>> p;
bool strict = false;

bool dfs2(int id, long long x) {
  if (used[id]) {
    if (solved[id] != x)
      return false;
    else
      return true;
  }
  used[id] = true;
  solved[id] = x;
  if (solved[id] <= 0)
    return false;
  for (int i = 0; i < p[id].size(); i++) {
    if (!dfs2(p[id][i].first, p[id][i].second - x))
      return false;
  }
  return true;
}

bool dfs(int id, long long a, long long b) {
  if (used[id]) {
    if (c[id].first != a) {
      strict = true;
      x = (c[id].second - b) / (a - c[id].first);
      return true;
    } else {
      if (c[id].second == b)
        return false;
      else
        return true;
    }
  }
  used[id] = true;
  c[id].first = a;
  c[id].second = b;
  for (int i = 0; i < p[id].size(); i++) {
    if (dfs(p[id][i].first, -a, p[id][i].second - b))
      return true;
  }
  return false;
}

int main() {
  cin >> n >> m;
  c.resize(n);
  used.resize(n);
  solved.resize(n);
  p.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, s;
    cin >> u >> v >> s;
    u--;
    v--;
    p[u].push_back(make_pair(v, s));
    p[v].push_back(make_pair(u, s));
  }
  if (dfs(0, 1, 0)) {
    used.clear();
    used.resize(n);
    if (strict && dfs2(0, x)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    long long minX = 0, maxX = 10000000000000;
    for (int i = 0; i < n; i++) {
      if (c[i].first == 1)
        minX = max(minX, -c[i].second + 1);
      else
        maxX = min(maxX, c[i].second - 1);
    }
    if (maxX - minX + 1 > 0)
      cout << maxX - minX + 1 << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}
