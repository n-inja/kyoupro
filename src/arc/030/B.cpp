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
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<vector<int>> p(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  function<pair<int, int>(int, int)> dfs;
  dfs = [&](int i, int from) {
    pair<int, int> ret;
    if (v[i]) ret.second += 1;
    for (auto &j : p[i]) {
      if (j == from) continue;
      auto r = dfs(j, i);
      if (r.second > 0)
        ret.first += r.first + 2;
      ret.second += r.second;
    }
    return ret;
  };
  cout << dfs(x, -1).first << endl;
  return 0;
}
