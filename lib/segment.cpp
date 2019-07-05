#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

class RMQ {
  vector<long long> data;

public:
  static const long long INF = 100000000000;
  int n;

  RMQ(int _) {
    n = _;
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = INF;
  }

  void update(int index, long long val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // [a, b)
  long long query(int a, int b, int k, int l, int r) {
    if (a < 0)
      return 0;
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return data[k];
    else
      return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                 query(a, b, k * 2 + 2, (r + l) / 2, r));
  }

  long long query(int a, int b) { return query(a, b, 0, 0, n); }
};

template<typename T>
class tRMQ {
  vector<T> data;
  T unit;

public:
  int n;
  function<T(const T &, const T &)> f;

  tRMQ(int _, T u, function<T(T, T)> bi) {
    unit = u;
    f = bi;
    n = 1;
    while (n < _) {
      n <<= 1;
    }
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = unit;
  }

  tRMQ(vector<T> &v, T u, function<T(T, T)> bi) {
    unit = u;
    f = bi;
    n = 1;
    while (n < v.size())
      n <<= 1;
    data.resize(n * 4, u);
    for (int i = 0; i < v.size(); i++) {
      data[n + i - 1] = v[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  void update(int index, T val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // [a, b)
  T query(int a, int b, int k, int l, int r) {
    if (a < 0 || r <= a || b <= l)
      return unit;
    if (a <= l && r <= b)
      return data[k];
    else
      return f(query(a, b, k * 2 + 1, l, (l + r) / 2),
               query(a, b, k * 2 + 2, (r + l) / 2, r));
  }

  T query(int a, int b) { return query(a, b, 0, 0, n); }
};

tRMQ<ll> minrmq(int n) {
  return tRMQ<ll>(n, 10000000000000000LL, [](ll r, ll l) { return min(l, r); });
}

tRMQ<ll> maxrmq(int n) {
  return tRMQ<ll>(n, -10000000000000000LL,
                  [](ll r, ll l) { return max(l, r); });
}

tRMQ<ll> sumrmq(int n) {
  return tRMQ<ll>(n, 0, [](ll l, ll r) { return l + r; });
}

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
// ref:https://www65.atwiki.jp/kyopro-lib/pages/15.html

int main() {
  vector<ll> v({1, 2, 3, 4, 5, 6, 7, 8});
  RSQRAQ2<ll> q(v, 0, [](ll l, ll r) {
                  return l + r;
                }, [](ll l, int len) {
                  return l;
                }, [](ll l, ll r) {
                  return max(l, r);
                }
  );
  for (int i = 0; i < v.size(); i++) cerr << q.query(i, i + 1) << endl;
  q.update(0, 8, 3);
  cerr << q.query(0, 8) << endl;
  for (int i = 0; i < v.size(); i++) cerr << q.query(i, i + 1) << endl;

  return 0;
}