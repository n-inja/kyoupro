#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n;
vector<vector<pair<int, ll>>> p;
vector<int> col;

void dfs(int i, int c) {
  if (col[i] >= 0) {
    return;
  }
  col[i] = c;
  for (auto &v : p[i]) {
    dfs(v.first, (c + v.second) % 2);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  p.resize(n);
  col.resize(n);
  for (int i = 0; i < n; i++) col[i] = -1;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    p[u].emplace_back(v, w);
    p[v].emplace_back(u, w);
  }
  dfs(0, 0);
  for (int i = 0; i < n; i++) cout << col[i] << endl;
  return 0;
}
