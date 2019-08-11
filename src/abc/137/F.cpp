#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll P;
  cin >> P;
  vector<ll> a(P);
  for (int i = 0; i < P; i++)
    cin >> a[i];
  vector<ll> b(P);
  vector<ll> fac(P + 2), facInv(P + 2);
  fac[0] = 1;
  facInv[0] = 1;

  auto power = [&](ll e, ll x) {
    ll r = 1;
    e %= P;
    while (x) {
      if (x & 1) {
        r *= e;
        r %= P;
      }
      e *= e;
      e %= P;
      x >>= 1;
    }
    return r;
  };

  for (int i = 0; i < P + 1; i++) {
    fac[i + 1] = (fac[i] * (i + 1)) % P;
    facInv[i + 1] = (facInv[i] * power(i + 1, P - 2)) % P;
  }
  auto comb = [&](int N, int K) {
    if (N < K || K < 0 || N < 0)
      return 0LL;
    if (N == 0 || K == 0 || K == N)
      return 1LL;
    return ((fac[N] * facInv[K]) % P * facInv[N - K]) % P;
  };

  for (int i = 0; i < P; i++) {
    if (a[i] == 0) continue;
    b[0] += 1;
    b[0] %= P;
    vector<ll> po(P);
    po[0] = 1;
    for (int j = 1; j < P; j++) {
      po[j] = (po[j - 1] * (P - i)) % P;
    }
    for (int j = 0; j < P; j++) {
      b[j] += P - (po[P - 1 - j] * comb(P - 1, j)) % P;
      b[j] %= P;
    }
  }

  cout << b[0];
  for (int i = 1; i < P; i++) cout << " " << b[i];
  cout << endl;
  return 0;
}
