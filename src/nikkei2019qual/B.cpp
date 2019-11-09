#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll P = 998244353;

ll pow(ll e, ll x) {
  ll r = 1;
  while (x) {
    if (x % 2) {
      r = (r * e) % P;
    }
    e = (e * e) % P;
    x >>= 1;
  }
  return r;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  if (d[0] > 0) {
    cout << 0 << endl;
    return 0;
  }
  sort(d.begin(), d.end());
  ll ans = 1;
  ll mx = 0;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    mx = max(mx, d[i]);
    mp[d[i]]++;
  }
  if (mp[0] != 1) {
    cout << 0 << endl;
    return 0;
  }
  for (ll i = 1; i <= mx; i++) {
    ans *= pow(mp[i - 1], mp[i]);
    ans %= P;
  }
  cout << ans << endl;

  return 0;
}
