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
};

vector<vector<long long>> dp;

long long f(vector<long long> &v, int k) {
  int n = v.size();
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j - 1 - v[i] >= 0) {
        dp[i + 1][j] =
            ((dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - v[i]]) % P + P) % P;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % P;
      }
    }
  }

  long long ret = 0;
  for (int i = 0; i <= k; i++)
    ret = (ret + dp[n][i]) % P;
  return ret;
}
long long g(vector<long long> &v, int k) {
  int n = v.size();
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j - 1 - v[i] >= 0) {
        dp[i + 1][j] =
            ((dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - v[i]]) % P + P) % P;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % P;
      }
    }
  }

  return dp[n][k];
}

int main() {
  dp.resize(51);
  for (int i = 0; i < 51; i++)
    dp[i].resize(6000);
  int n;
  long long k;
  bool zero = false;
  cin >> n >> k;
  // C cmb(1000000);
  vector<long long> a(n), b, c(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  b = a;
  long long l = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      zero = true;
    while (b[i] > 0) {
      b[i] >>= 1;
      c[i]++;
    }
    l += c[i];
  }
  if (zero) {
    long long ans = 0;
    ans = (ans + f(c, min(l, k))) % P;
    cout << ans << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int s = c[i];
      c[i] = 0;
      if (min(k, l) - s >= 0) {
        ans = (ans + f(c, min(k, l) - s)) % P;
      }
      c[i] = max(s - 1, 0);
    }
    ans = (ans + g(c, min(k, l))) % P;
    cout << ans << endl;
  }

  return 0;
}
