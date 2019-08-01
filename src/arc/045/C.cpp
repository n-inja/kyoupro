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

  int n;
  ll x;
  cin >> n >> x;
  vector<vector<pair<int, ll>>> p(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    ll y;
    cin >> a >> b >> y;
    a--;
    b--;
    p[a].emplace_back(b, y);
    p[b].emplace_back(a, y);
  }
  function<void(int, int, int)> dfs;
  vector<ll> cost(n);
  dfs = [&](int i, int from, ll c) {
    cost[i] = c;
    for (auto &v : p[i]) {
      if (v.first == from) continue;
      dfs(v.first, i, c ^ v.second);
    }
  };
  dfs(0, -1, 0);
  ll ans = 0;
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    ans += mp[x ^ cost[i]];
    mp[cost[i]]++;
  }
  cout << ans << endl;

  return 0;
}
