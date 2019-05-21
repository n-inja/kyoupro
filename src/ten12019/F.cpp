#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 998244353;

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

C cmb(202020);

ll f(ll l, ll sum) {
  ll two = sum - l;
  ll one = l - two;
  if (two < 0 || one < 0) return 0;
  return ((cmb.fac[one + two] * cmb.facInv[one]) % P * cmb.facInv[two]) % P;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int s = 0; s < x; s++) {
      ll temp = ((cmb.fac[n] * cmb.facInv[i]) % P * cmb.facInv[n - i]) % P;
      ans += (temp * f(i, s)) % P;
      ans %= P;
    }
  }
  for (int i = 1; x + i <= 2 * n; i += 2) {
    if (i + 1 >= x - 1) {
      if (x % 2) {
        ans += ((cmb.fac[n] * cmb.facInv[(x + i) / 2]) % P * cmb.facInv[n - (x + i) / 2]) % P;
        ans %= P;
      }
    } else {
      for (int j = 0; j <= n; j++) {
        ans += (f(j, x - i - 2) * cmb.comb(n, i + j + 1));
        ans %= P;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
