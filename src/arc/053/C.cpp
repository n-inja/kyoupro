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
  vector<pair<ll, ll>> pos, neg;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (a - b >= 0) pos.emplace_back(a, b);
    else neg.emplace_back(a, b);
  }
  using pll = pair<ll, ll>;
  sort(neg.begin(), neg.end(), [](const pll &l, const pll &r) {
    return l.first < r.first;
  });
  sort(pos.begin(), pos.end(), [](const pll &l, const pll &r) {
    return l.second < r.second;
  });
  ll ans = 0;
  ll now = 0;
  for (int i = 0; i < neg.size(); i++) {
    now += neg[i].first;
    ans = max(ans, now);
    now -= neg[i].second;
  }
  for (int i = 0; i < pos.size(); i++) {
    now += pos[i].first;
    now -= pos[i].second;
  }
  for (int i = 0; i < pos.size(); i++) {
    now += pos[i].second;
    ans = max(ans, now);
    now -= pos[i].first;
  }
  cout << ans << endl;
  return 0;
}
