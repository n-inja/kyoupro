#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

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
  return tRMQ<ll>(n, 0,
                  [](ll r, ll l) { return max(l, r); });
}

tRMQ<ll> sumrmq(int n) {
  return tRMQ<ll>(n, 0, [](ll l, ll r) { return l + r; });
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  int all = 0;

  auto r = sumrmq(n);

  ll diff = 0;
  for (int i = 0; i < k; i++) {
    diff += r.query(p[i], n);
    r.update(p[i], 1);
  }
  if (diff) {
    ans++;
  } else {
    all++;
  }

  for (int i = k; i < n; i++) {
    bool is_change = false;
    ll minus = r.query(0, p[i - k]);
    if (minus) is_change = true;
    r.update(p[i - k], 0);
    ll plus = r.query(p[i], n);
    r.update(p[i], 1);
    if (plus) is_change = true;
    diff += plus - minus;
    if (is_change) {
      if (diff == 0) {
        all++;
      } else {
        ans++;
      }
    }
  }

  if (all) ans++;
  cout << ans << endl;
  return 0;
}
