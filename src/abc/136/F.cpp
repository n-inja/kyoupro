#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

long long P = 998244353;

class C {
public:
  int n;
  vector<long long> fac, inv, facInv;

  long long power(long long e, long long x) {
    ll r = 1;
    while (x) {
      if (x % 2 == 1) {
        r *= e;
        r %= P;
      }
      e *= e;
      e %= P;
      x >>= 1;
    }
    return r;
  }

  C(int n_) {
    n = n_;
    fac.resize(n + 1);
    inv.resize(n + 1);
    facInv.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++)
      fac[i] = (i * fac[i - 1]) % P;
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
      inv[i] = power(i, P - 2);
    facInv[0] = facInv[1] = 1;
    for (int i = 2; i <= n; i++)
      facInv[i] = (inv[i] * facInv[i - 1]) % P;
  }

  long long comb(int N, int K) {
    if (N < K || K < 0 || N < 0)
      return 0;
    if (N == 0 || K == 0 || K == N)
      return 1;
    return ((fac[N] * facInv[K]) % P * facInv[N - K]) % P;
  }

  long long hcomb(int N, int K) {
    if (N == 0 && K == 0)
      return 1;
    return comb(N + K - 1, K);
  }

  long long mul(long long a, long long b) { return (a * b) % P; }

  long long add(long long a, long long b) { return (a + b) % P; }

  // find c
  // where a^c = b (mod P)
  long long dlp(long long a, long long b) {
    long long m = ceil(sqrt(P));
    map<long long, long long> mp;
    for (int i = 0; i < m; i++)
      mp[power(a, i)] = i;
    long long ainvm = power(power(a, m), P - 2);
    cout << m << endl;
    for (int i = 0; i < m; i++) {
      if (mp.find(b) != mp.end()) {
        return i * m + mp[b];
      }
      b = mul(b, ainvm);
    }
    return -1;
  }
};

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

C cmp(10);

struct N {
  ll x, y;
  int i;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> ps(n);
  for (int i = 0; i < n; i++) cin >> ps[i].x >> ps[i].y;
  for (int i = 0; i < n; i++) ps[i].i = i;
  ll ans = 0;
  vector<ll> xs(n), ys(n), ul(n), ur(n), dl(n), dr(n);
  map<ll, int> xmp, ymp;
  for (int i = 0; i < n; i++) {
    xs[i] = ps[i].x, ys[i] = ps[i].y;
    xmp[xs[i]] = 0;
    ymp[ys[i]] = 0;
  }
  int c = 0;
  for (auto &v : xmp) {
    v.second = c++;
  }
  c = 0;
  for (auto &v : ymp) {
    v.second = c++;
  }

  // x-first
  sort(ps.begin(), ps.end(), [](const N &l, const N &r) {
    if (l.x == r.x)
      return l.y < r.y;
    return l.x < r.x;
  });
  ll bef = -1;
  vector<int> buf(n);
  int bi = 0, bj = 0;
  auto xr = sumrmq(n);
  for (int i = 0; i < n; i++) {
    if (bef != xmp[ps[i].x]) {
      for (; bi < bj; bi++) {
        int j = buf[bi];
        xr.update(j, xr.query(j, j + 1) + 1);
      }
    }
    ul[ps[i].i] = xr.query(0, ymp[ps[i].y]);
    dl[ps[i].i] = xr.query(ymp[ps[i].y] + 1, n);
    buf[bj++] = ymp[ps[i].y];
    bef = xmp[ps[i].x];
  }

  // x-rev-first
  bef = -1;
  bi = 0, bj = 0;
  auto yr = sumrmq(n);
  sort(ps.begin(), ps.end(), [](const N &l, const N &r) {
    if (l.x == r.x)
      return l.y < r.y;
    return l.x > r.x;
  });
  for (int i = 0; i < n; i++) {
    if (bef != xmp[ps[i].x]) {
      for (; bi < bj; bi++) {
        int j = buf[bi];
        yr.update(j, yr.query(j, j + 1) + 1);
      }
    }
    ur[ps[i].i] = yr.query(0, ymp[ps[i].y]);
    dr[ps[i].i] = yr.query(ymp[ps[i].y] + 1, n);
    buf[bj++] = ymp[ps[i].y];
    bef = xmp[ps[i].x];
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  for (int i = 0; i < n; i++) {
    ll l = lower_bound(xs.begin(), xs.end(), ps[i].x) - xs.begin();
    ll r = xs.end() - upper_bound(xs.begin(), xs.end(), ps[i].x);
    ll u = lower_bound(ys.begin(), ys.end(), ps[i].y) - ys.begin();
    ll d = ys.end() - upper_bound(ys.begin(), ys.end(), ps[i].y);
    ll t = (cmp.power(2, l) - 1 + P) % P;
    t += (cmp.power(2, r) - 1 + P) % P;
    t %= P;
    t += (cmp.power(2, u) - 1 + P) % P;
    t %= P;
    t += (cmp.power(2, d) - 1 + P) % P;
    t %= P;
    t += P - cmp.power(2, ul[ps[i].i]) + 1;
    t %= P;
    t += P - cmp.power(2, ur[ps[i].i]) + 1;
    t %= P;
    t += P - cmp.power(2, dl[ps[i].i]) + 1;
    t %= P;
    t += P - cmp.power(2, dr[ps[i].i]) + 1;
    t %= P;
    ans += t;
    ans %= P;
  }
  ll all = (n * (cmp.power(2, n) - 1)) % P;
  ans = (all - ans + P) % P;

  cout << ans << endl;

  return 0;
}
