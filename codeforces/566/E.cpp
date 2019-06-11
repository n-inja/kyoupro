#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;
ll Q = 1000000006;

ll p(ll e, ll x) {
  if (x == 0) return 1;
  if (x % 2 == 0) return p((e * e) % P, x / 2);
  return (e * p(e, x - 1)) % P;
}

vvl mul(vvl a, vvl b) {
  int n = a.size();
  int m = b[0].size();
  vvl ret(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < a[i].size(); k++) {
        ret[i][j] += (a[i][k] * b[k][j]) % Q;
        ret[i][j] %= Q;
      }
    }
  }
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;

  vvl S({
            {1, 1, 1, 2, -4},
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 1},
        });
  vvl I({
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1},
        });
  ll m = n - 3;
  vvl v({{0},
         {0},
         {0},
         {3},
         {1}});

  for (ll k = m; k > 0; k >>= 1) {
    if (k % 2 == 1) {
      I = mul(S, I);
    }
    S = mul(S, S);
  }
  auto out = mul(I, v);
  ll cnum = out[0][0];

  vvl S1({
             {1, 1, 1},
             {1, 0, 0},
             {0, 1, 0},
         }),
      I1({
             {1, 0, 0},
             {0, 1, 0},
             {0, 0, 1},
         });
  for (ll k = m; k > 0; k >>= 1) {
    if (k % 2 == 1) {
      I1 = mul(S1, I1);
    }
    S1 = mul(S1, S1);
  }
  vvl v1({{0},
          {0},
          {1}});
  out = mul(I1, v1);
  ll f1num = out[0][0];

  vvl S2({
             {1, 1, 1},
             {1, 0, 0},
             {0, 1, 0},
         }),
      I2({
             {1, 0, 0},
             {0, 1, 0},
             {0, 0, 1},
         });

  for (ll k = m; k > 0; k >>= 1) {
    if (k % 2 == 1) {
      I2 = mul(S2, I2);
    }
    S2 = mul(S2, S2);
  }
  vvl v2({{0},
          {1},
          {0}});
  out = mul(I2, v2);
  ll f2num = out[0][0];

  vvl S3({
             {1, 1, 1},
             {1, 0, 0},
             {0, 1, 0},
         }),
      I3({
             {1, 0, 0},
             {0, 1, 0},
             {0, 0, 1},
         });

  for (ll k = m; k > 0; k >>= 1) {
    if (k % 2 == 1) {
      I3 = mul(S3, I3);
    }
    S3 = mul(S3, S3);
  }
  vvl v3({{1},
          {0},
          {0}});
  out = mul(I3, v3);
  ll f3num = out[0][0];

  ll ans = 1;
  ans *= p(c, cnum);
  ans %= P;
  ans *= p(f1, f1num);
  ans %= P;
  ans *= p(f2, f2num);
  ans %= P;
  ans *= p(f3, f3num);
  ans %= P;

  cout << ans << endl;

  return 0;
}
