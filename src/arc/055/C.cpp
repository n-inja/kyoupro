#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

const int MAX_STRING_SIZE = 500000;

ll base = 1007;

vector<ll> MODS({2147483647, 6700417, 524287, 1000000007, 1000000009}

);

vector<vector<ll>> invs(MODS.size()), pows(MODS.size());

ll powm(ll e, ll x, ll m) {
  if (x == 0) return 1;
  if (x == 1) return e;
  if (x % 2 == 0) return powm((e * e) % m, x / 2, m);
  return (e * powm(e, x - 1, m)) % m;
}

void RHinit() {
  int i = 0;
  for (auto &p : MODS) {
    invs[i].resize(MAX_STRING_SIZE + 1);
    invs[i][0] = 1;
    ll inv = powm(base, p - 2, p);
    for (int j = 1; j <= MAX_STRING_SIZE; j++) {
      invs[i][j] = (invs[i][j - 1] * inv) % p;
    }
    pows[i].resize(MAX_STRING_SIZE + 1);
    pows[i][0] = 1;
    for (int j = 1; j <= MAX_STRING_SIZE; j++) {
      pows[i][j] = (pows[i][j - 1] * base) % p;
    }
    i++;
  }
}

struct RH {
  int n;
  string s;
  vector<vector<ll>> hs;

  RH(string &s) : s(s) {
    if (pows[0].empty()) {
      RHinit();
    }
    n = s.size();
    hs.resize(MODS.size());
    for (int i = 0; i < MODS.size(); i++) {
      hs[i].resize(n + 1);
      hs[i][0] = 0;
      for (int j = 0; j < n; j++) {
        hs[i][j + 1] = (hs[i][j] + pows[i][j] * s[j]) % MODS[i];
      }
    }
  }

  // [l, r)
  vector<ll> substr(int l, int r) {
    vector<ll> ret(MODS.size());
    for (int i = 0; i < MODS.size(); i++) {
      ret[i] = (hs[i][r] - hs[i][l] + MODS[i]) % MODS[i];
      ret[i] *= invs[i][l];
      ret[i] %= MODS[i];
    }
    return ret;
  }

  vector<ll> substrlen(int i, int l) {
    return substr(i, i + l);
  }
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  RHinit();
  string s;
  cin >> s;
  int n = s.size();
  string t = s;
  reverse(t.begin(), t.end());
  RH rh(s), rhr(t);
  ll ans = 0;

  // ABC AC

  for (int i = 2; i < n - 2; i++) {
    if (i + 1 <= (n - i - 1)) continue;
    if (s[i] == s.back() && s[i + 1] == s[0]) {
      // find a
      // i + 1, n - 2
      ll la = 1, ra = min(i - 1, n - 2 - i);
      if (la > ra) continue;
      auto f = [&](ll m) {
        return rh.substrlen(0, m) == rh.substrlen(i + 1, m);
      };
      if (f(ra)) {
        la = ra;
      }
      while (ra - la > 1) {
        ll m = (la + ra) / 2;
        if (f(m)) {
          la = m;
        } else {
          ra = m;
        }
      }
      ll lb = 1, rb = min(i - 1, n - (i + 2));
      if (lb > rb) continue;
      auto g = [&](ll m) {
        return rhr.substrlen(n - i - 1, m) == rhr.substrlen(0, m);
      };
      if (g(rb)) {
        lb = rb;
      }
      while (rb - lb > 1) {
        ll m = (lb + rb) / 2;
        if (g(m)) {
          lb = m;
        } else {
          rb = m;
        }
      }
      ans += max(0LL, lb + la - (n - i - 2));
    }
  }
  cout << ans << endl;
  return 0;
}
