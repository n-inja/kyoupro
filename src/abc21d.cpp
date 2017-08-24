#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

using namespace std;

const long long P = 1000000007;

class C {
public:
  int n;
  vector<long long> fac, inv, facInv;
  long long power(long long e, long long x) {
    if(x == 0) return 1;
    if(x == 1) return e;
    if(x % 2 == 0) return power((e * e) % P, x / 2);
    return (e * power(e, x - 1)) % P;
  }
  C(int n_) {
    n = n_;
    fac.resize(n + 1);
    inv.resize(n + 1);
    facInv.resize(n + 1);
    fac[1] = 1;
    for(int i = 2; i <= n; i++) fac[i] = (i * fac[i - 1]) % P;
    inv[1] = 1;
    for(int i = 2; i <= n; i++) inv[i] = power(i, P - 2);
    facInv[1] = 1;
    for(int i = 2; i <= n; i++) facInv[i] = (inv[i] * facInv[i - 1]) % P;
  }
  long long comb(int N, int K) {
    if(N == 0 || K == 0 || K == N) return 1;
    if(N < K || K < 0 || N < 0) return 0;
    return ((fac[N] * facInv[K]) % P * facInv[N - K]) % P;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  C c(max(n, k));
  long long ans = 0;
  for(int i = 1; i <= k; i++) ans = (ans + (c.comb(n, i) * c.comb(k - 1, i - 1)) % P) % P;
  cout << ans << endl;
  return 0;
}
