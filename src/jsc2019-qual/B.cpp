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

ll P = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> t(n);
  vector<ll> s(2000);
  for (int i = 0; i < n; i++) s[a[i] - 1]++;
  vector<ll> ss(2001), iss(2001);
  for (int i = 0; i < 2000; i++) ss[i + 1] = ss[i] + s[i];
  for (int i = 0; i < 2000; i++) iss[1999 - i] = iss[2000 - i] + s[1999 - i];

  ll ans = 0;
  ll tmp = (k * (k - 1)) / 2;
  tmp %= P;
  auto r = sumrmq(2001);
  for (int i = 0; i < n; i++) {
    t[i] = r.query(a[i] + 1, 2001);
    ans += (t[i] * k) % P;
    ans %= P;
    ans += (iss[a[i]] * tmp) % P;
    ans %= P;
    r.update(a[i], r.query(a[i], a[i] + 1) + 1);
  }
  cout << ans << endl;
  return 0;
}
