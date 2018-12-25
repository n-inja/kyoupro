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

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  C c(n + 2);
  long long d[100002] = {0};
  long long sum[100002] = {0};
  d[0] = 0;
  d[1] = 1;
  for (int i = 2; i <= n; i++)
    d[i] = c.div(1, i);
  sum[0] = 0;
  for (int i = 0; i <= n; i++)
    sum[i + 1] = (sum[i] + d[i + 1]) % P;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (a[i] * sum[i + 1]) % P;
    ans %= P;
    ans += (a[i] * sum[n - i]) % P;
    ans %= P;
    ans += (P - a[i]);
    ans %= P;
  }
  cout << (ans * c.fac[n]) % P << endl;
  return 0;
}
