#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
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
    fac[1] = 1;
    for (int i = 2; i <= n; i++)
      fac[i] = (i * fac[i - 1]) % P;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
      inv[i] = power(i, P - 2);
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
  long long pair(int N, int K) { return (comb(N, K) * fac[K]) % P; }
};

C comb(10000);

long long add(long long a, long long b) { return (a + b) % P; }

long long mul(long long a, long long b) { return (a * b) % P; }

int main() {
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  // dp[i人以下のグループ][j人]: 通り数
  long long dp[1001][1001] = {0};
  dp[0][0] = 1;
  for (int i = 1; i <= b; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (i < a)
        continue;
      for (int k = c; k <= d && j - i * k >= 0; k++) {
        dp[i][j] =
            add(dp[i][j],
                mul(dp[i - 1][j - i * k],
                    mul(comb.pair(n - j + i * k, i * k),
                        mul(comb.power(comb.facInv[i], k), comb.facInv[k]))));
      }
    }
  }
  cout << dp[b][n] << endl;
  return 0;
}
