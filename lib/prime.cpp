#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

const long long P = 1000000007;

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

template<long long M>
class mint {
public:
  ll a;

  mint(ll a = 0) : a(a % M) {}

  ll &v() { return a; }

  ll const &v() const { return a; }

  mint operator+(const mint rhs) const {
    return mint(*this) += rhs;
  }

  mint operator-(const mint rhs) const {
    return mint(*this) -= rhs;
  }

  mint operator*(const mint rhs) const {
    return mint(*this) *= rhs;
  }

  mint operator/(const mint rhs) const {
    return mint(*this) /= rhs;
  }

  mint pow(ll x) const {
    mint ret(1);
    mint acc = a;
    while (x > 0) {
      if (x % 2) {
        ret *= acc;
      }
      acc *= acc;
      x >>= 1;
    }
    return ret;
  }

  mint &operator+=(const mint rhs) {
    a += rhs.a;
    a %= M;
    return *this;
  }

  mint &operator-=(const mint rhs) {
    a -= rhs.a + M;
    a %= M;
    return *this;
  }

  mint &operator*=(const mint rhs) {
    a *= rhs.a;
    a %= M;
    return *this;
  }

  mint &operator/=(const mint rhs) {
    a *= rhs.pow(M - 2).v();
    a %= M;
    return *this;
  }

};

std::ostream &operator<<(std::ostream &stream, const mint<P> &m) {
  return stream << m.v();
}


ll power(ll e, ll x) {
  if (x == 0) return 1;
  ll acc = e;
  ll ret = 1;
  while (x > 0) {
    if (x % 2) {
      ret *= acc;
    }
    acc *= acc;
    x >>= 1;
  }
  return ret;
}

ll tot(ll x) {
  map<ll, int> primes;
  ll y = x;
  for (ll i = 2; i * i <= y; i++) {
    if (y % i == 0) {
      primes[i]++;
      y /= i;
      i--;
    }
  }
  if (y > 1) primes[y]++;

  ll ret = 1;
  for (auto &it : primes) {
    ret *= (power(it.first, it.second) - power(it.first, it.second - 1));
  }
  return ret;
}

int main() {
  C cmp(100);
  long long c = cmp.dlp(100, 192971657);
  cout << c << endl;
  cout << cmp.power(100, c) << endl;
  cout << cmp.power(100, 10000000) << endl;

  mint<P> a(10), b(100), d(100);
  cout << d / a << endl;
  cout << tot(1000000007) << endl;
  return 0;
}
