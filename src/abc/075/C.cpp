#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n, m;
vector<vector<int>> p;
vector<int> pre, low;
int bridge = 0;

int pr = 1;

int dfs(int i, int from) {
  if (pre[i] > 0) return low[i];
  pre[i] = pr;
  low[i] = pr;
  for (auto &j : p[i]) {
    if (j == from) continue;
    pr++;
    int to = dfs(j, i);
    if (to < pre[i]) {
      low[i] = min(low[i], to);
    } else {
      if (low[j] == pre[j]) bridge++;
    }
  }
  return low[i];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  pre.resize(n);
  low.resize(n);
  dfs(0, -1);
  cout << bridge << endl;

  return 0;
}
