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
  ll I;
  cin >> n >> I;
  ll k = 8 * I / n;

  ll diff = (1LL << k) - 1;
  if (k > 60) diff = (1LL << 60) - 1;
  vector<ll> a(n);
  set<ll> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) s.insert(a[i]);
  vector<ll> c;
  for (auto &i : s) c.push_back(i);

  sort(a.begin(), a.end());
  ll m = c.size();
  c.push_back(1LL << 50);
  ll ans = n;
  for (int i = 0; i < c.size(); i++) {
    ll up = c[min(i + diff, m)];
    ll l = lower_bound(a.begin(), a.end(), c[i]) - a.begin();
    ll r = a.end() - upper_bound(a.begin(), a.end(), up);
    ans = min(ans, l + r);
  }
  cout << ans << endl;

  return 0;
}
