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
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  vector<int> ans(n + 1);
  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[v[i]]++;
  map<int, vector<int>> mpinv;
  for (auto &pr : mp) {
    mpinv[pr.second].push_back(pr.first);
  }
  vector<int> par(n + 1);
  int rest = 0;
  for (int i = 1; i <= n; i++) par[i] = n / i;
  int j = 1;
  for (int part = 1; part <= n; part++) {
    int base = mp.size() + rest / part;
    ans[base] = max(ans[base], part);
    if (mpinv.find(part) != mpinv.end()) {
      for (auto &k : mpinv[part]) {
        auto it = mp.find(k);
        rest += it->second;
        mp.erase(it);
      }
    }
  }
  for (int i = n - 1; i > 0; i--) ans[i] = max(ans[i], ans[i + 1]);

  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
  return 0;
}
