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

ll dp[101010][202] = {0};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  vector<ll> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  ll cnt = 0;
  for (int i = 0; i < n; i++)
    if (v[i] <= x)
      cnt++;
  dp[x][n] = 1;
  for (int i = x; i > 0; i--) {
    for (int j = n; j > 0; j--) {
      if (dp[i][j] == 0)
        continue;
      dp[i][j - 1] += (dp[i][j] * (j - 1)) % P;
      dp[i][j - 1] %= P;
      dp[i % v[j - 1]][j - 1] += dp[i][j];
      dp[i % v[j - 1]][j - 1] %= P;
    }
  }
  ll ans = 0;
  for (ll i = 0; i <= x; i++) {
    ans += (i * dp[i][0]) % P;
    ans %= P;
  }
  cout << ans << endl;

  return 0;
  ll ans2 = 0;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    p[i] = i;
  do {
    ll y = x;
    for (int i = 0; i < n; i++) {
      y %= v[p[i]];
    }
    ans2 += y;
    ans2 %= P;
  } while (next_permutation(p.begin(), p.end()));
  cerr << ans2 << endl;

  return 0;
}
