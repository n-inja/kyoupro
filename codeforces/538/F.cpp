#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll P = 1000000007;

class C {
public:
  int n;
  vector<long long> fac, inv, facInv;
  long long power(long long e, long long x) {
    if (x == 0)
      return 1;
    if (x == 1)
      return e;
    if (x % 2 == 0)
      return power((e * e) % P, x / 2);
    return (e * power(e, x - 1)) % P;
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
C cmp(300);

struct RSQRAQ2 {
  int n;
  vector<ll> dat, lazy;

  RSQRAQ2() {}
  RSQRAQ2(int n_) {
    n = 1;
    while (n < n_)
      n *= 2;
    dat.assign(n * 2, 1);
    lazy.assign(n * 2, 1);
  }

  void eval(int len, int k) {
    if (lazy[k] == 1)
      return;
    if (k * 2 + 1 < n * 2 - 1) {
      lazy[2 * k + 1] *= lazy[k];
      lazy[2 * k + 1] %= P;
      lazy[2 * k + 2] *= lazy[k];
      lazy[2 * k + 2] %= P;
    }
    dat[k] *= cmp.power(lazy[k], len);
    dat[k] %= P;
    lazy[k] = 1;
  }

  // [a, b)
  ll update(int a, int b, ll x, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return dat[k];
    if (a <= l && r <= b) {
      lazy[k] *= x;
      lazy[k] %= P;
      return (dat[k] * cmp.power(lazy[k], (r - l))) % P;
    }
    return dat[k] = (update(a, b, x, 2 * k + 1, l, (l + r) / 2) *
                     update(a, b, x, 2 * k + 2, (l + r) / 2, r)) %
                    P;
  }
  ll update(int a, int b, ll x) { return update(a, b, x, 0, 0, n); }

  // [a, b)
  ll query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return 1;
    if (a <= l && r <= b)
      return dat[k];
    ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return (vl * vr) % P;
  }
  ll query(int a, int b) { return query(a, b, 0, 0, n); }
};
// ref:https://www65.atwiki.jp/kyopro-lib/pages/15.html

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
      lazy[2 * k + 1] |= lazy[k];
      lazy[2 * k + 2] |= lazy[k];
    }
    dat[k] |= lazy[k];
    lazy[k] = 0;
  }

  // [a, b)
  ll update(int a, int b, ll x, int k, int l, int r) {
    eval(r - l, k);
    if (b <= l || r <= a)
      return dat[k];
    if (a <= l && r <= b) {
      lazy[k] |= x;
      return dat[k] | lazy[k];
    }
    return dat[k] = update(a, b, x, 2 * k + 1, l, (l + r) / 2) |
                    update(a, b, x, 2 * k + 2, (l + r) / 2, r);
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
    return vl | vr;
  }
  ll query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> primes({2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,
                      37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
                      83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137,
                      139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                      197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                      263, 269, 271, 277, 281, 283, 293});
  map<int, int> primeset;
  int p = primes.size();
  ll pinv[p] = {0};
  for (int i = 0; i < p; i++)
    pinv[i] = (1 - cmp.power(primes[i], P - 2) + P) % P;
  for (int i = 0; i < p; i++) {
    primeset[primes[i]] = i;
  }
  int n, q;
  cin >> n >> q;
  RSQRAQ2 rmq(n);
  RSQRAQ rs(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    rmq.update(i, i + 1, a);
    ll mask = 0;
    for (int j = 0; j < p; j++)
      if (a % primes[j] == 0)
        mask |= (1LL << j);
    rs.update(i, i + 1, mask);
  }
  for (int i = 0; i < q; i++) {
    string s;
    int l, r;
    cin >> s >> l >> r;
    l--;
    if (s == "MULTIPLY") {
      int b;
      cin >> b;
      rmq.update(l, r, b);
      ll mask = 0;
      for (int j = 0; j < p; j++)
        if (b % primes[j] == 0)
          mask |= (1LL << j);
      rs.update(l, r, mask);
    } else {
      ll ans = rmq.query(l, r);
      ll mask = rs.query(l, r);
      for (int j = 0; j < p; j++) {
        if (mask & (1LL << j)) {
          ans *= pinv[j];
          ans %= P;
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}
