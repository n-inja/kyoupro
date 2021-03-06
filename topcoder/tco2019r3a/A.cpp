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

struct FamilySeatingArrangement {
  int countWays(vector<int> a, int k) {
    C cmb(2000);
    int n = a.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        if (i + 1 <= n && j + 1 <= k) {
          dp[i + 1][j + 1] += dp[i][j];
          dp[i + 1][j + 1] %= P;
        }
        if (i + 1 <= n) {
          dp[i + 1][j] += (j * dp[i][j]) % P;
          dp[i + 1][j] %= P;
        }
      }
    }
    ll ans = 0;
    for (int j = 1; j <= k; j++) {
      ll temp = ((dp[n][j] * cmb.fac[k]) % P * cmb.facInv[k - j]) % P;
      ll child = 1;
      ll rest = k - j + 1;
      for (int i = 0; i < n; i++) {
        child *= cmb.power(rest, a[i]);
        child %= P;
      }
      temp *= child;
      temp %= P;
      ans += temp;
      ans %= P;
    }
    return ans;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  FamilySeatingArrangement a;
  cout << a.countWays({2, 1}, 2) << endl;
  cout << a.countWays({2, 1}, 3) << endl;
  cout << a.countWays({2}, 3) << endl;
  cout << a.countWays({1}, 1) << endl;
  return 0;
}
