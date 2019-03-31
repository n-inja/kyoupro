#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

class Increase {
public:
  int n, flowMax = 1000000;
  vector<map<int, int>> p;
  vector<int> parent;
  Increase(int _n, vector<map<int, int>> _p) {
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
    for (auto &to : p[id])
      if (to.second > 0) {
        int next = dfs(to.first, id, min(flow, to.second));
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
int n, m;
vector<map<int, int>> p;

int main() {
  cin >> n >> m;
  p.resize(n + 2);
  for (int i = 0; i < m; i++) {
    int t, f;
    cin >> t >> f;
    p[t][f] = 1;
    p[f][t] = 1;
  }
  vector<int> p6, p4, p3;
  for (int i = 1; i <= n; i++) {
    if (p[i].size() >= 6)
      p6.push_back(i);
    if (p[i].size() == 4)
      p4.push_back(i);
    if (p[i].size() % 2 == 1)
      p3.push_back(i);
  }
  if (p3.size() > 0) {
    cout << "No" << endl;
  } else if (p6.size() > 0) {
    cout << "Yes" << endl;
  } else if (p4.size() >= 3) {
    cout << "Yes" << endl;
  } else if (p4.size() == 2) {
    p[0][p4[0]] = 10;
    p[p4[1]][n + 1] = 10;
    Increase flow(n + 2, p);
    if (flow.solve() == 2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
