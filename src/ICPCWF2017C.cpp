#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
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

bool solve() {
  int r, c;
  if (scanf("%d %d", &r, &c) == EOF)
    return false;
  long long mat[100][100] = {0};
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      cin >> mat[i][j];
  long long rmax[100] = {0}, cmax[100] = {0}, sum = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      rmax[i] = max(rmax[i], mat[i][j]);
      cmax[j] = max(cmax[j], mat[i][j]);
      sum += mat[i][j];
    }

  long long sum_ = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (mat[i][j] > 0)
        sum_++;

  map<long long, pair<vector<int>, vector<int>>> mp;
  for (int i = 0; i < r; i++) {
    if (rmax[i] > 0)
      mp[rmax[i]].first.push_back(i);
  }
  for (int j = 0; j < c; j++) {
    if (cmax[j] > 0)
      mp[cmax[j]].second.push_back(j);
  }
  for (auto &it : mp) {
    int n = 2 + it.second.first.size() + it.second.second.size();
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++)
      p[i].resize(n);
    for (int i = 0; i < it.second.first.size(); i++)
      p[0][1 + i] = 1;
    for (int i = 0; i < it.second.second.size(); i++)
      p[1 + it.second.first.size() + i][n - 1] = 1;
    for (int i = 0; i < it.second.first.size(); i++) {
      for (int j = 0; j < it.second.second.size(); j++) {
        if (mat[it.second.first[i]][it.second.second[j]] > 0) {
          p[1 + i][1 + it.second.first.size() + j] = 1;
        }
      }
    }
    Increase solver(n, p);
    sum_ += (it.first - 1) *
            (it.second.first.size() + it.second.second.size() - solver.solve());
  }
  cout << sum - sum_ << endl;
  return true;
}

int main() {
  while (true) {
    if (!solve())
      break;
  }
  return 0;
}
