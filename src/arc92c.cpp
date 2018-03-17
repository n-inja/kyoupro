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

class Increase {
public:
  int n, flowMax = 1000000;
  vector<vector<int>> p;
  vector<int> parent;
  Increase(int _n, vector<vector<int>> _p) {
    n = _n;
    p = _p;
    parent.resize(n);
  }
  int dfs(int id, int from, int flow) {
    if (parent[id] != id)
      return 0;
    parent[id] = from;
    if (id == n - 1)
      return flow;
    for (int i = 0; i < n; i++)
      if (p[id][i] > 0) {
        int next = dfs(i, id, min(flow, p[id][i]));
        if (next > 0)
          return next;
      }
    return 0;
  }
  int solve() {
    int ret = 0, flow;
    for (int i = 0; i < n; i++)
      parent[i] = i;

    while ((flow = dfs(0, -1, flowMax)) > 0) {
      int now = n - 1;
      ret += flow;
      while (parent[now] >= 0) {
        p[parent[now]][now] -= flow;
        p[now][parent[now]] += flow;
        now = parent[now];
      }
      for (int i = 0; i < n; i++)
        parent[i] = i;
    }
    return ret;
  }
};

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> ab(n), cd(n);
  for (int i = 0; i < n; i++)
    cin >> ab[i].first >> ab[i].second;
  for (int i = 0; i < n; i++)
    cin >> cd[i].first >> cd[i].second;

  vector<vector<int>> path(2 * n + 2);
  for (int i = 0; i < 2 * n + 2; i++) {
    path[i].resize(2 * n + 2);
  }
  for (int i = 0; i < n; i++) {
    path[0][i + 1] = 1;
    path[n + 1 + i][2 * n + 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ab[i].first < cd[j].first && ab[i].second < cd[j].second) {
        path[i + 1][n + 1 + j] = 1;
      }
    }
  }
  Increase solver(2 * n + 2, path);
  cout << solver.solve() << endl;
  return 0;
}
