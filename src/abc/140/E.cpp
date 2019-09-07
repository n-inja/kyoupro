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
  using pll = pair<ll, ll>;
  vector<pll> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first;
  }
  for (int i = 0; i < n; i++) p[i].second = i, p[i].first = -p[i].first;
  sort(p.begin(), p.end());
  ll ans = 0;
  set<int> s;
  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound(p[i].second);
    ll ll = -1, lr = -1, rl = n, rr = n;
    if (it != s.end()) {
      rl = *it;
      it++;
      if (it != s.end()) {
        rr = *it;
      }
      it--;
    }
    if (it != s.begin()) {
      it--;
      lr = *it;
      if (it != s.begin()) {
        it--;
        ll = *it;
      }
    }
    ans += ((lr - ll) * (rl - p[i].second) + (rr - rl) * (p[i].second - lr)) * (-p[i].first);
    s.insert(p[i].second);
  }
  cout << ans << endl;
  return 0;
}
