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
  static const long long INF = 100000000000;
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a[i] -= k;
  map<ll, int> f;
  ll sum = 0;
  f[0] = 0;
  vector<ll> s(n + 1);
  for (int i = 0; i < n; i++) {
    sum += a[i];
    f[sum] = 0;
    s[i + 1] = sum;
  }
  int c = 0;
  for (auto &v : f) v.second = c++;
  vector<ll> v(c);
  for (int i = 0; i <= n; i++) v[f[s[i]]]++;
  auto r = sumrmq(c);
  for (int i = 0; i < c; i++) {
    r.update(i, v[i]);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    r.update(f[s[i]], r.query(f[s[i]], f[s[i]] + 1) - 1);
    auto it = f.lower_bound(s[i]);
    if (it == f.end()) continue;
    int id = it->second;
    ans += r.query(id, c);
  }
  cout << ans << endl;
  return 0;
}
