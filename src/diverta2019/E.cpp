#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
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

ll dp[505050] = {0};

int main() {
  C cmp(505050);
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  vll s(n + 1);
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] ^ a[i];
  }
  ll all = s[n];
  ll b = 0;
  for (int i = 1; i <= n; i++) if (s[i] == all) b++;
  if (all) {
    ll zs = 1;
    ll bs = 0;
    for (int i = 0; i < n; i++) {
      if (s[i + 1] == all) {
        bs += zs;
        bs %= P;
      } else if (s[i + 1] == 0) {
        zs += bs;
        zs %= P;
      }
    }
    ans += zs;
  } else {
    // 0 split
    if (b == 0) {
      ans += 1;
    } else {
      ans += cmp.power(2, b - 1);
    }

    // other
    vector<int> zeros;
    for (int i = 0; i <= n; i++) if (s[i] == 0) zeros.push_back(i);
    vector<int> ssum(n + 1);
    for (int i = 0; i < n; i++) {
      ssum[i + 1] = ssum[i];
      if (s[i + 1] == 0) ssum[i + 1]++;
    }
    map<ll, ll> nonzero;
    map<ll, ll> nonzerosum;
    map<ll, int> bef;

    for (int i = 1; i < zeros.size(); i++) {
      for (int j = zeros[i - 1] + 1; j < zeros[i]; j++) {
        if (nonzero.find(s[j]) == nonzero.end()) {
          nonzero[s[j]] = (1);

          ans += 1;
          ans %= P;

          nonzerosum[s[j]] = 1;
          bef[s[j]] = j;
        } else {
          ll now = ((ssum[j] - ssum[bef[s[j]]]) * nonzerosum[s[j]]) % P;
          now += nonzero[s[j]];
          now %= P;

          ans += now;
          ans %= P;

          nonzero[s[j]] = now;
          nonzerosum[s[j]] = (now + nonzerosum[s[j]]) % P;
          bef[s[j]] = j;
        }
      }
    }

  }
  cout << ans << endl;

  return 0;
}
