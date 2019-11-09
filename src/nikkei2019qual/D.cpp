#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

template<typename T>
struct RSQRAQ2 {
  int n;
  T unit;
  function<T(T, T)> update_f, sum_f, query_f;
  vector<T> dat, lazy;

  RSQRAQ2() {}

  RSQRAQ2(int n_, T unit, function<T(T, T)> update_f, function<T(T, int)> sum_f, function<T(T, T)> query_f)
    : unit(unit), update_f(update_f), sum_f(sum_f), query_f(query_f) {
    n = 1;
    while (n < n_)
      n *= 2;
    dat.assign(n * 2, unit);
    lazy.assign(n * 2, unit);
  }

  RSQRAQ2(vector<T> v, T unit, function<T(T, T)> update_f, function<T(T, int)> sum_f, function<T(T, T)> query_f)
    : unit(unit), update_f(update_f), sum_f(sum_f), query_f(query_f) {
    n = 1;
    while (n < v.size()) n <<= 1;
    dat.assign(n * 2, unit);
    lazy.assign(n * 2, unit);
    for (int i = 0; i < v.size(); i++) {
      dat[n + i - 1] = v[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      dat[i] = query_f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  void eval(int len, int k) {
    if (lazy[k] == unit)
      return;
    if (k * 2 + 1 < n * 2 - 1) {
      lazy[2 * k + 1] = update_f(lazy[2 * k + 1], lazy[k]);
      lazy[2 * k + 2] = update_f(lazy[2 * k + 2], lazy[k]);
    }
    dat[k] = update_f(dat[k], sum_f(lazy[k], len));
    lazy[k] = unit;
  }

  // [a, b)
  T update(int a, int b, T x, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return dat[k];
    if (a <= l && r <= b) {
      lazy[k] = update_f(lazy[k], x);
      return query_f(dat[k], sum_f(lazy[k], r - l));
    }
    return dat[k] = query_f(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                            update(a, b, x, 2 * k + 2, (l + r) / 2, r));
  }

  T update(int a, int b, T x) { return update(a, b, x, 0, 0, n); }

  // [a, b)
  T query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return unit;
    if (a <= l && r <= b)
      return dat[k];
    return query_f(query(a, b, 2 * k + 1, l, (l + r) / 2), query(a, b, 2 * k + 2, (l + r) / 2, r));
  }

  T query(int a, int b) { return query(a, b, 0, 0, n); }
};

struct N {
  ll l, r, c;
};

bool operator<(const N &l, const N &r) {
  return l.r < r.r;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<N> ns(m);
  ll INF = 1000000000000000LL;
  for (int i = 0; i < m; i++) cin >> ns[i].l >> ns[i].r >> ns[i].c;
  RSQRAQ2<ll> r(n, INF, [](ll l, ll r) {
    return min(l, r);
  }, [](ll l, int t) {
    return l;
  }, [](ll l, ll r) {
    return min(l, r);
  });
  r.update(0, 1, 0LL);
  sort(ns.begin(), ns.end());
  for (int i = 0; i < m; i++) {
    ll v = r.query(ns[i].l - 1, ns[i].r) + ns[i].c;
    r.update(ns[i].l, ns[i].r, v);
  }
  if (r.query(n - 1, n) == INF) {
    cout << -1 << endl;
  } else {
    cout << r.query(n - 1, n) << endl;
  }

  return 0;
}
