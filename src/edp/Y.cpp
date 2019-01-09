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
struct N {
  int i, j;
  long long v;
};
vector<N> ns;
vector<vector<int>> p;
int h, w, n;

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
C cmp(202020);

int main() {
  cin >> h >> w >> n;
  ns.resize(n + 2);
  p.resize(n + 2);
  ns[0] = N{0, 0, 1};
  for (int i = 1; i <= n; i++) {
    cin >> ns[i].i >> ns[i].j;
    ns[i].i--;
    ns[i].j--;
    ns[i].v = 0;
  }
  ns[n + 1] = N{h - 1, w - 1, 0};
  sort(ns.begin(), ns.end(), [](const N &l, const N &r) {
    if (l.i == r.i)
      return l.j < r.j;
    return l.i < r.i;
  });
  for (int i = 0; i < n + 2; i++)
    for (int j = i + 1; j < n + 2; j++) {
      if (ns[i].i <= ns[j].i && ns[i].j <= ns[j].j)
        p[i].push_back(j);
    }
  for (int i = 0; i <= n; i++) {
    for (auto &j : p[i]) {
      int h = (ns[j].i - ns[i].i);
      int w = (ns[j].j - ns[i].j);
      long long diff =
          (ns[i].v *
           cmp.mul(cmp.fac[h + w], cmp.mul(cmp.facInv[h], cmp.facInv[w]))) %
          P;
      if (i != 0) {
        ns[j].v += P - diff;
      } else {
        ns[j].v += diff;
      }
      ns[j].v %= P;
    }
  }
  cout << ns[n + 1].v << endl;

  return 0;
}
