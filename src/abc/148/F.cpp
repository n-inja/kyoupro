#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, u, v;
vector<vector<int>> p, parentk;
vector<int> d2, d, parent;

void dfs(int i, int dep, int from) {
  d[i] = dep;
  parent[i] = from;
  if (i == v) return;
  for (auto &j : p[i]) {
    if (j == from) continue;
    dfs(j, dep + 1, i);
  }
}

int lca(int i, int j) {
  if (d[i] < d[j]) swap(i, j);
  int k = 22;
  while (k >= 0 && d[i] > d[j]) {
    if (d[parentk[k][i]] >= d[j]) {
      i = parentk[k][i];
    }
    k--;
  }
  k = 22;
  if (i == j) return i;
  while (k >= 0 && i != j) {
    if (parentk[k][i] != parentk[k][j]) {
      i = parentk[k][i];
      j = parentk[k][j];
    }
    k--;
  }
  return parent[i];
}

void dfs2(int i, int dep, int from) {
  if (i == v) return;
  d2[i] = dep;
  for (auto &j : p[i]) {
    if (from == j) continue;
    dfs2(j, dep + 1, i);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> u >> v;
  u--;
  v--;
  p.resize(n);
  d.resize(n);
  d2.resize(n);
  parent.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  dfs(u, 0, u);
  ll ans = 0;
  vector<int> q;
  int w = v;
  while (w != u) {
    q.push_back(w);
    w = parent[w];
  }
  q.push_back(u);
  if (q.size() == 1) {
    cout << 0 << endl;
  }
  if (q.size() % 2 == 0) {
    v = q[q.size() / 2 - 1];
    dfs2(q[q.size() / 2], 0, -1);
    cout << q.size() / 2 - 1 + *max_element(d2.begin(), d2.end()) << endl;
  } else {
    v = q[q.size() / 2];
    dfs2(q[q.size() / 2 + 1], 0, -1);
    cout << (q.size() - 2) / 2 + *max_element(d2.begin(), d2.end()) + 1 << endl;
  }
  return 0;
}
