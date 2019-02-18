#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct RSQRAQ {
  int n;
  vector<ll> dat, lazy;

  RSQRAQ() {}
  RSQRAQ(int n_) {
    n = 1;
    while (n < n_)
      n *= 2;
    dat.assign(n * 2, 0);
    lazy.assign(n * 2, 0);
  }

  void eval(int len, int k) {
    if (lazy[k] == 0)
      return;
    if (k * 2 + 1 < n * 2 - 1) {
      lazy[2 * k + 1] = max(lazy[2 * k + 1], lazy[k]);
      lazy[2 * k + 2] = max(lazy[2 * k + 2], lazy[k]);
    }
    dat[k] = max(dat[k], lazy[k]);
    lazy[k] = 0;
  }

  // [a, b)
  ll update(int a, int b, ll x, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return dat[k];
    if (a <= l && r <= b) {
      lazy[k] = max(lazy[k], x);
      return max(dat[k], lazy[k]);
    }
    return dat[k] = max(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                        update(a, b, x, 2 * k + 2, (l + r) / 2, r));
  }
  ll update(int a, int b, ll x) { return update(a, b, x, 0, 0, n); }

  // [a, b)
  ll query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return 0;
    if (a <= l && r <= b)
      return dat[k];
    ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
  ll query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  RSQRAQ rmq(n);
  for (int i = 0; i < m; i++) {
    ll l, r, t;
    cin >> t >> l >> r;
    rmq.update(l - 1, r, t);
  }
  ll ans = 1000000000LL * n;
  for (int i = 0; i < n; i++) {
    ans -= (1000000000LL - rmq.query(i, i + 1));
  }
  cout << ans << endl;
  return 0;
}
