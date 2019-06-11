#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

long long P;

ll power(ll e, ll x) {
  if (x == 0) return 1;
  if (x % 2 == 0) return power((e * e) % P, x / 2);
  return (e * power(e, x - 1)) % P;
}

vvl mul(vvl a, vvl b) {
  int n = a.size();
  int m = b[0].size();
  vvl ret(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < a[i].size(); k++) {
        ret[i][j] += (a[i][k] * b[k][j]) % P;
        ret[i][j] %= P;
      }
    }
  }
  return ret;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll l, a, b;
  cin >> l >> a >> b >> P;

  ll p10[1010] = {0};
  p10[0] = 1;
  for (int i = 0; i < 19; i++) p10[i + 1] = p10[i] * 10;
  ll ans = 0;

  for (int first = 1; first <= 19 && l > 0; first++) {
    ll mx = p10[first];
    if (mx <= a) continue;
    ll sz = min(l, (mx - a + b - 1) / b);

    vvl v({{ans, a % P, 1}});

    vvl S({
              {p10[first] % P, 0,     0},
              {1,              1,     0},
              {0,              b % P, 1},
          });
    vvl I({{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}});

    for (ll k = sz; k > 0; k >>= 1) {
      if (k % 2 == 1) {
        I = mul(S, I);
      }
      S = mul(S, S);
    }

    S = mul(v, I);

    ans = S[0][0];

    l -= sz;
    a += b * sz;
  }
  cout << ans << endl;

  return 0;
}
