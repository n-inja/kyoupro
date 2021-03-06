#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

long long P = 1000000007;

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
C cmp(202020);

ll solve(ll n, ll a, ll b, ll c) {
  ll D = b * b - 4 * a * c;
  if (D < 0) {
    return 0;
  } else if (D == 0) {
    if (b % (2 * a) == 0) {
      return cmp.comb(n, -b / (a * 2));
    }
    return 0;
  } else {
    ll d = sqrt(D);
    if (d * d == D) {
      ll chi1 = -b - d;
      ll chi2 = -b + d;
      ll ans = 0;
      if (chi1 % (2 * a) == 0) {
        ans += cmp.comb(n, chi1 / (2 * a));
      }
      if (chi2 % (2 * a) == 0) {
        ans += cmp.comb(n, chi2 / (2 * a));
      }
      return ans % P;
    }
    return 0;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll m, k;
    cin >> m >> k;
    ll ans = 0;
    if (m % 2 == 0) {
      ans += solve(m / 2, -2, m, -k);
    } else {
      ans += (solve(m / 2, -2, m, -k) + solve(m / 2, -2, m - 2, m / 2 - k)) % P;
    }
    cout << ans << endl;
  }
  return 0;
}
