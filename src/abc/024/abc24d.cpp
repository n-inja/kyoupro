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

const long long PRIME = 1000000007;

class C {
public:
  int n;
  vector<long long> fac, inv, facInv;
  long long power(long long e, long long x) {
    if(x == 0) return 1;
    if(x == 1) return e;
    if(x % 2 == 0) return power((e * e) % PRIME, x / 2);
    return (e * power(e, x - 1)) % PRIME;
  }
  C(int n_) {
    n = n_;
    fac.resize(n + 1);
    inv.resize(n + 1);
    facInv.resize(n + 1);
    fac[1] = 1;
    for(int i = 2; i <= n; i++) fac[i] = (i * fac[i - 1]) % PRIME;
    inv[1] = 1;
    for(int i = 2; i <= n; i++) inv[i] = power(i, PRIME - 2);
    facInv[1] = 1;
    for(int i = 2; i <= n; i++) facInv[i] = (inv[i] * facInv[i - 1]) % PRIME;
  }
  long long comb(int N, int K) {
    if(N == 0 || K == 0 || K == N) return 1;
    if(N < K || K < 0 || N < 0) return 0;
    return ((fac[N] * facInv[K]) % PRIME * facInv[N - K]) % PRIME;
  }
};

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  // b
  // a c
  C prime(1);
  long long x = 10000000000, y = 10000000000;
  long long cinv = prime.power(c, PRIME - 2);
  long long binv = prime.power(b, PRIME - 2);
  for(long long i = 0; i < 199999999; i++) {
    long long x1 = ((a * (i + 1)) % PRIME * cinv) % PRIME;
    long long y1 = ((a * (i + 1)) % PRIME * binv) % PRIME;
    if(x1 + y1 - 2 == i) {
      if(x1 - 1 < x) {
        x = x1 - 1;
        y = y1 - 1;
      } else if(x1 - 1 == x && y1 - 1 < y) {
        y = y1 - 1;
      }
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
