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
  vector<pair<ll, ll>> ps(n), qs(n);
  for (int i = 0; i < n; i++) cin >> ps[i].first >> ps[i].second;
  auto f = [](pair<ll, ll> p) { return make_pair(p.first + p.second, p.first - p.second); };
  for (int i = 0; i < n; i++) qs[i] = f(ps[i]);
  auto g = [](pair<ll, ll> p) {
    return make_pair((p.first + p.second) / 2, (p.first - p.second) / 2);
  };
  ll INF = 1010101001010LL;
  ll l = INF, r = -INF, u = INF, d = -INF;
  for (int i = 0; i < n; i++) {
    l = min(l, qs[i].first);
    r = max(r, qs[i].first);
    u = min(u, qs[i].second);
    d = max(d, qs[i].second);
  }
  vector<pair<ll, ll>> fans({make_pair(l, u)});

  ll ds = (max(r - l, d - u) + 1) / 2;
  fans.emplace_back(l + ds, u + ds);
  fans.emplace_back(r - ds, u + ds);
  fans.emplace_back(l + ds, d - ds);
  fans.emplace_back(r - ds, d - ds);

  for (int i = 0; i < fans.size(); i++) {
    auto ans = g(fans[i]);
    set<ll> s;
    for (int j = 0; j < n; j++) s.insert(abs(ps[j].first - ans.first) + abs(ps[j].second - ans.second));
    if (s.size() == 1) {
      cout << ans.first << " " << ans.second << endl;
      return 0;
    }
  }
  return 0;
}
