#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  vector<vector<int>> p(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  vector<char> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  vector<char> d(k);
  for (int i = 0; i < k; i++) {
    int e;
    cin >> e;
    d[i] = c[e - 1];
  }

  auto f = [&](char c, char d) {
    if (c == 'G' && d == 'C') return x;
    if (c == 'C' && d == 'P') return x;
    if (c == 'P' && d == 'G') return x;
    if (c == d) return y;
    return 0;
  };

  vector<vector<int>> memo(n, vector<int>(k, -1));
  function<int(int, int)> dfs;
  dfs = [&](int i, int turn) {
    if (turn == k) return 0;
    if (memo[i][turn] >= 0) return memo[i][turn];
    int ret = f(c[i], d[turn]) + dfs(i, turn + 1);
    for (auto &j : p[i]) {
      ret = max(ret, f(c[j], d[turn]) + dfs(j, turn + 1));
    }
    return memo[i][turn] = ret;
  };

  cout << dfs(0, 0) << endl;

  return 0;
}
