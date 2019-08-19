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
  int n, q;
  cin >> n >> q;
  vector<vector<int>> p(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  vector<ll> lz(n), ans(n);
  for (int i = 0; i < q; i++) {
    ll j, x;
    cin >> j >> x;
    j--;
    lz[j] += x;
  }
  function<void(int, int, ll)> dfs = [&](int i, int from, ll v) {
    ans[i] = lz[i] + v;
    for (auto &j : p[i]) {
      if (j == from) continue;
      dfs(j, i, lz[i] + v);
    }
  };
  dfs(0, -1, 0);
  cout << ans[0];
  for (int i = 1; i < n; i++) cout << " " << ans[i];
  cout << endl;
  return 0;
}
