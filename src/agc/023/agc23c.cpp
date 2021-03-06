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
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= n; i++)
      fac[i] = (i * fac[i - 1]) % P;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
      inv[i] = power(i, P - 2);
    facInv[0] = 1;
    facInv[1] = 1;
    for (int i = 2; i <= n; i++)
      facInv[i] = (inv[i] * facInv[i - 1]) % P;
  }
  long long comb(int N, int K) {
    if (N == 0 || K == 0 || K == N)
      return 1;
    if (N < K || K < 0 || N < 0)
      return 0;
    return ((fac[N] * facInv[K]) % P * facInv[N - K]) % P;
  }
};

long long mul(long long a, long long b) { return (a * b) % P; }

long long add(long long a, long long b) { return (a + b) % P; }

int main() {
  int n;
  cin >> n;
  C c(2000001);
  if (n == 2) {
    cout << 1 << endl;
  } else if (n == 3) {
    cout << 4 << endl;
  } else {
    long long ans = 0;
    vector<long long> dp(2000001);
    dp[0] = dp[1] = 0;
    for (int i = 2; i < n; i++) {
      dp[i] = mul(c.comb(i - 1, n - 1 - i), mul(c.fac[i], c.fac[n - i - 1]));
    }
    for (int i = 1; i < n; i++) {
      ans = add(ans, mul(i, (dp[i] - dp[i - 1] + P) % P));
    }
    cout << ans << endl;
  }
  return 0;
}
