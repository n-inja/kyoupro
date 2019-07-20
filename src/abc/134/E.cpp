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
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = 0;
  }
  int c = 1;
  for (auto &v : mp) {
    v.second = c++;
  }
  auto r = maxrmq(n + 3);
  r.update(0, 0);
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ll b = r.query(0, mp[a[i]]) + 1;
    r.update(mp[a[i]] - 1, b);
    ans = max(ans, b);
  }
  cout << ans << endl;
  return 0;
}
