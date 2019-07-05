#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

// return (x, y) (a * x + b * y = gcd(a, b))
pair<long long, long long> exeuclid(long long a, long long b) {
  if (b == 0)
    return make_pair(1, 0);
  pair<long long, long long> ret = exeuclid(b, a % b);
  ret.first -= a / b * ret.second;
  return make_pair(ret.second, ret.first);
}

// v := [(modulo, reminder)]
// moduloes should be coprime
long long CRT(vector<pair<ll, ll>> v) {
  long long mod = 1;
  long long ret = 0;
  for (int i = 0; i < v.size(); i++) {
    pair<ll, ll> xy = exeuclid(mod, v[i].first);
    long long M = mod * v[i].first;
    long long l = ((v[i].second * mod) % M) * xy.first;
    l %= M;
    long long r = ((ret * v[i].first) % M) * xy.second;
    r %= M;
    ret = (l + r) % M;
    ret += M;
    ret %= M;
    mod = M;
  }
  return ret;
}

ll mod_pow(ll e, ll x, ll p) {
  ll r = 1;
  e %= p;
  while (x) {
    if (x & 1) {
      r *= e;
      r %= p;
    }
    e *= e;
    e %= p;
    x >>= 1;
  }
  return r;
}

template<class T>
T extgcd(T a, T b, T &x, T &y) {
  for (T u = y = 1, v = x = 0; a;) {
    T q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}

ll mod_inv(ll a, ll b) {
  return (exeuclid(a, b).first % b + b) % b;
}

template<int mod, int primitive_root>
class NTT {
public:
  int get_mod() const { return mod; }

  void _ntt(vector<ll> &a, int sign) {
    const int n = a.size();
    assert((n ^ (n & -n)) == 0); //n = 2^k

    const int g = 3; //g is primitive root of mod
    int h = (int) mod_pow(g, (mod - 1) / n, mod); // h^n = 1
    if (sign == -1) h = (int) mod_inv(h, mod); //h = h^-1 % mod

    //bit reverse
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1);
      if (j < i) swap(a[i], a[j]);
    }

    for (int m = 1; m < n; m *= 2) {
      const int m2 = 2 * m;
      const ll base = mod_pow(h, n / m2, mod);
      ll w = 1;
      for (int x = 0; x < m; x++) {
        for (int s = x; s < n; s += m2) {
          ll u = a[s];
          ll d = a[s + m] * w % mod;
          a[s] = u + d;
          if (a[s] >= mod) a[s] -= mod;
          a[s + m] = u - d;
          if (a[s + m] < 0) a[s + m] += mod;
        }
        w = w * base % mod;
      }
    }

    for (auto &x : a) if (x < 0) x += mod;
  }

  void ntt(vector<ll> &input) {
    _ntt(input, 1);
  }

  void intt(vector<ll> &input) {
    _ntt(input, -1);
    const int n_inv = mod_inv(input.size(), mod);
    for (auto &x : input) x = x * n_inv % mod;
  }

  // 畳み込み演算を行う
  vector<ll> convolution(const vector<ll> &a, const vector<ll> &b) {
    int ntt_size = 1;
    while (ntt_size < a.size() + b.size()) ntt_size *= 2;

    vector<ll> _a = a, _b = b;
    _a.resize(ntt_size);
    _b.resize(ntt_size);

    ntt(_a);
    ntt(_b);

    for (int i = 0; i < ntt_size; i++) {
      (_a[i] *= _b[i]) %= mod;
    }

    intt(_a);
    return _a;
  }
};

ll garner(vector<pair<ll, ll>> mr, int mod) {
  mr.emplace_back(mod, 0);

  vector<ll> coffs(mr.size(), 1);
  vector<ll> constants(mr.size(), 0);
  for (int i = 0; i < mr.size() - 1; i++) {
    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
    ll v = (mr[i].second - constants[i]) * mod_inv(coffs[i], mr[i].first) % mr[i].first;
    if (v < 0) v += mr[i].first;

    for (int j = i + 1; j < mr.size(); j++) {
      (constants[j] += coffs[j] * v) %= mr[j].first;
      (coffs[j] *= mr[i].first) %= mr[j].first;
    }
  }

  return constants[mr.size() - 1];
}

typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;
NTT_1 ntt1;
NTT_2 ntt2;
NTT_2 ntt3;
// ref: https://math314.hateblo.jp/entry/2015/05/07/014908

// NTT
// c[i] = for j,k a[j] + b[k] if j + k == i mod P
vector<ll> mod_conv(vector<ll> a, vector<ll> b, ll P) {
  for (auto &i : a) i %= P;
  for (auto &i : b) i %= P;
  auto v1 = ntt1.convolution(a, b);
  auto v2 = ntt2.convolution(a, b);
  auto v3 = ntt3.convolution(a, b);
  int n = v2.size();
  vector<ll> ret(n);
  for (int i = 0; i < n; i++) {
    if (v1[i] != v2[i]) cerr << v1[i] << " " << v2[i] << endl;
    ret[i] = garner(vector<pair<ll, ll>>(
        {
            make_pair(ntt1.get_mod(), v1[i]),
            make_pair(ntt2.get_mod(), v2[i]),
            make_pair(ntt3.get_mod(), v3[i])
        }), P);
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  auto c = mod_conv(a, b, 1000000007);
  for (int i = 1; i <= 2 * n; i++) {
    cout << c[i] << endl;
  }
  return 0;
}