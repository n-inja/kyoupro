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

long long add(long long a, long long b) { return (a + b) % P; }

long long mul(long long a, long long b) { return (a * b) % P; }

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
};

int main() {
  C cmp(100100);
  string s;
  cin >> s;
  long long b_a[100002] = {0}, a_c[100002] = {0}, a_q[100002] = {0},
            b_q[100002] = {0};
  int n = s.size();
  b_a[0] = 0;
  b_q[0] = 0;
  for (int i = 0; i < n; i++) {
    b_a[i + 1] = b_a[i] + (s[i] == 'A' ? 1 : 0);
    b_q[i + 1] = b_q[i] + (s[i] == '?' ? 1 : 0);
  }
  a_c[n] = 0;
  a_q[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    a_c[i] = a_c[i + 1] + (s[i] == 'C' ? 1 : 0);
    a_q[i] = a_q[i + 1] + (s[i] == '?' ? 1 : 0);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B' || s[i] == '?') {
      ans = add(
          ans, mul(mul(b_a[i], a_c[i + 1]), cmp.power(3, b_q[i] + a_q[i + 1])));
      if (b_q[i] > 0) {
        ans = add(ans, mul(mul(b_q[i], a_c[i + 1]),
                           cmp.power(3, b_q[i] + a_q[i + 1] - 1)));
      }
      if (a_q[i + 1] > 0) {
        ans = add(ans, mul(mul(b_a[i], a_q[i + 1]),
                           cmp.power(3, b_q[i] + a_q[i + 1] - 1)));
      }
      if (b_q[i] > 0 && a_q[i + 1] > 0) {
        ans = add(ans, mul(mul(b_q[i], a_q[i + 1]),
                           cmp.power(3, b_q[i] + a_q[i + 1] - 2)));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
