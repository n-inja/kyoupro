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

template <typename T> class tRMQ {
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
    data.resize(n * 2 + 1);
    for (int i = 0; i < n + 1; i++) {
      if (i < v.size())
        data[i + n] = v[i];
      else
        data[i + n] = u;
    }
    for (int i = n - 1; i >= 0; i--) {
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

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> v(n);
  for (int i = 0; i < n; i++)
    v[i] = (1LL << 31) - 1LL;
  tRMQ<ll> rmq(v, (1LL << 31) - 1LL, [](ll l, ll r) { return min(l, r); });
  int c, l, r;
  for (int i = 0; i < q; i++) {
    cin >> c >> l >> r;
    if (c) {
      cout << rmq.query(l, r + 1) << endl;
    } else {
      rmq.update(l, r);
    }
  }

  return 0;
}