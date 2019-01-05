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
  long long div(long long a, long long b) { return (a * power(b, P - 2)) % P; }
};

long long pw(long long e, long long x) {
  long long ret = 1;
  while (x > 0) {
    if (x % 2 == 0) {
      e *= e;
    } else {
      ret *= e;
      e *= e;
    }
    x >>= 1;
  }
  return ret;
}

int main() {
  C cmp(1 << 1);
  long long n;
  int k;
  cin >> n >> k;
  map<long long, int> mp;
  while (n % 2 == 0) {
    mp[2]++;
    n /= 2;
  }
  for (long long i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n > 1)
    mp[n]++;

  long long ans = 1;
  vector<vector<long long>> dp(k + 1);
  for (int i = 0; i <= k; i++) {
    dp[i].resize(51);
  }
  for (auto &it : mp) {
    for (int i = 0; i <= k; i++)
      for (int j = 0; j <= it.second; j++)
        dp[i][j] = 0;
    dp[0][it.second] = 1;
    for (int i = 0; i < k; i++)
      for (int j = it.second; j >= 0; j--) {
        long long inv = cmp.power(j + 1, P - 2);
        for (int l = j; l >= 0; l--) {
          dp[i + 1][l] += (dp[i][j] * inv) % P;
          dp[i + 1][l] %= P;
        }
      }
    long long d = 1;
    long long now = 0;
    for (int i = 0; i <= it.second; i++) {
      now += (dp[k][i] * d) % P;
      now %= P;
      d *= it.first;
      d %= P;
    }
    ans *= now;
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}
