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
  vector<vector<long long>> p;
  vector<int> parent;
  Increase(int _n, vector<vector<long long>> _p) {
    n = _n;
    p = _p;
    parent.resize(n);
  }
  long long dfs(int id, int from, long long flow) {
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
  long long solve() {
    long long ret = 0, flow;
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
  int n, x, y;
  cin >> n >> x >> y;
  if (n > 500)
    return 1;
  vector<vector<long long>> p(n + 2);
  for (int i = 0; i < n + 2; i++)
    p[i].resize(n + 2);
  for (int i = 0; i < n - 1; i++) {
    int a, b, v;
    cin >> a >> b >> v;
    p[a][b] = p[b][a] = v;
  }
  for (int i = 0; i < x; i++) {
    int a;
    cin >> a;
    p[a][0] = p[0][a] = 10000000000000000;
  }
  for (int i = 0; i < y; i++) {
    int a;
    cin >> a;
    p[a][n + 1] = p[n + 1][a] = 10000000000000000;
  }
  Increase flow(n + 2, p);
  cout << flow.solve() << endl;
  return 0;
}
