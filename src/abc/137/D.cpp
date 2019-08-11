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
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> ab(n);
  using pll = pair<ll, ll>;
  map<ll, vector<ll>> mp;
  for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
  for (int i = 0; i < n; i++) {
    mp[ab[i].first].push_back(ab[i].second);
  }
  priority_queue<ll> q;
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    for (auto &v : mp[i + 1]) q.push(v);
    if (q.size()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
