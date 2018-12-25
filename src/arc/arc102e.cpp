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

long long P = 998244353;

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

int main() {
  int n, k;
  cin >> k >> n;
  C c(50000);
  long long p2[2020];
  p2[0] = 1;
  for (int i = 0; i < 2010; i++)
    p2[i + 1] = (p2[i] * 2) % P;
  for (int i = 2; i <= 2 * k; i++) {
    long long ans = 0;
    int p = 0;
    for (int j = 1; j <= k; j++)
      if (j < i - j && i - j <= k)
        p++;
    for (int j = 0; j <= min(n, p); j++) {
      if (i % 2 == 0) {
        ans = c.add(ans, c.mul(c.mul(p2[j], c.comb(p, j)),
                               c.add(c.hcomb(k - 2 * p + j - 1, n - j),
                                     c.hcomb(k - 2 * p + j - 1, n - j - 1))));
      } else {
        ans = c.add(ans, c.mul(c.mul(p2[j], c.comb(p, j)),
                               c.hcomb(k - 2 * p + j, n - j)));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
