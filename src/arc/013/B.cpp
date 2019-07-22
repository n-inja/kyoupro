#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  ll p[3];
  bool used[3];

  N(ll a, ll b, ll c) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    sort(p, p + 3);
  }

  bool ok(ll n) {
    for (int i = 2; i >= 0; i--) {
      if (used[i] || p[i] > n) continue;
      used[i] = true;
      return true;
    }
    return false;
  }

  ll get() {
    for (int i = 2; i >= 0; i--) {
      if (used[i]) continue;
      return p[i];
    }
    return 0;
  }

  void reset() {
    used[0] = used[1] = used[2] = 0;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<N> ns;
  for (int i = 0; i < n; i++) {
    ll p, q, r;
    cin >> p >> q >> r;
    ns.push_back(N(p, q, r));
  }

  ll ans = 1010101011010LL;
  for (ll i = 0; i <= 100; i++) {
    for (ll j = 0; j <= 100; j++) {
      bool ok = true;
      ll mx = 0;
      for (int k = 0; k < n; k++) {
        ns[k].reset();
        if (!(ns[k].ok(j) && ns[k].ok(i))) {
          ok = false;
          break;
        }
        mx = max(mx, ns[k].get());
      }
      if (ok)
        ans = min(ans, i * j * mx);
    }
  }
  cout << ans << endl;

  return 0;
}
