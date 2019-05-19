#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n, m;
vector<vector<pair<int, int>>> p;
vector<int> col;

void dfs(int i, int c) {
  if (col[i] >= 0) return;
  col[i] = c;
  for (auto &v : p[i]) {
    if (v.second) {
      dfs(v.first, 1 - c);
    } else {
      dfs(v.first, c);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  col.resize(n);
  for (int i = 0; i < n; i++) col[i] = -1;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    p[x].emplace_back(y, z % 2);
    p[y].emplace_back(x, z % 2);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (col[i] < 0) {
      ans++;
      dfs(i, 0);
    }
  }
  cout << ans << endl;

  return 0;
}
