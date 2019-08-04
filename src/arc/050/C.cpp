#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll po(ll e, ll x, ll m) {
  ll r = 1;
  while (x) {
    if (x % 2) {
      r = (r * e) % m;
    }
    x >>= 1;
    e = (e * e) % m;
  }
  return r;
}

ll f(ll e, ll x, ll m) {
  if (x == 0) {
    return 0;
  }
  if (x == 1) {
    return po(10, e - 1, m);
  }
  ll half = f(e, x / 2, m);
  if (x % 2 == 0) {
    return (half * po(10, x / 2 * e, m) + half) % m;
  } else {
    return (((half * po(10, x / 2 * e, m) + half) % m * po(10, e, m)) % m + po(10, e - 1, m)) % m;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll a, b, m;
  cin >> a >> b >> m;
  ll g = __gcd(a, b);
  ll ans = (f(g, a / g - 1, m) * 10 + 1) % m;
  ans *= (f(g, b / g - 1, m) * 10 + 1) % m;
  ans %= m;
  ans *= f(1, g, m);
  ans %= m;
  cout << ans << endl;

  return 0;
}
