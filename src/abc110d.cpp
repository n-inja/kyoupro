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
long long n, m;
map<long long, int> mp;

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

void f(long long n) {
  if (n == 1)
    return;
  for (long long j = 2; j * j <= n; j++) {
    if (n % j == 0) {
      mp[j]++;
      n /= j;
      j = 1;
    }
  }
  if (n != 1)
    mp[n]++;
}

int main() {
  cin >> n >> m;
  f(m);
  C c(500000);
  long long ans = 1;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    ans *= c.fac[n + it->second - 1];
    ans %= P;
    ans *= c.facInv[it->second];
    ans %= P;
    ans *= c.facInv[n - 1];
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}
