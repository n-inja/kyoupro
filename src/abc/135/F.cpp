#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

const int MAX_STRING_SIZE = 2000000;

ll base = 1007;

vector<ll> MODS({2147483647, 6700417, 524287, 1000000007}

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

  vector<ll> substr(int l, int r) {
    vector<ll> ret(MODS.size());
    for (int i = 0; i < MODS.size(); i++) {
      ret[i] = (hs[i][r] - hs[i][l] + MODS[i]) % MODS[i];
      ret[i] *= invs[i][l];
      ret[i] %= MODS[i];
    }
    return ret;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;

  RHinit();
  int m = s.size();
  for (int l = s.size(), i = 0; i < l; i++) s.push_back(s[i]);
  string u = s;
  while (u.size() < t.size()) {
    for (int l = u.size(), i = 0; i < l; i++) u.push_back(u[i]);
  }
  for (int l = u.size(), i = 0; i < l; i++) u.push_back(u[i]);
  RH uh(u), th(t);
  vector<bool> ok(u.size());
  for (int i = 0; i < u.size() - t.size(); i++) {
    ok[i] = uh.substr(i, i + t.size()) == th.substr(0, t.size());
  }
  for (int i = u.size() - t.size(); i < u.size(); i++) {
    int r = u.size() - i;
    ok[i] = (uh.substr(i, u.size()) == th.substr(0, r)) &&
            (uh.substr(0, t.size() - r) == th.substr(r, t.size()));
  }
  int ans = 0;
  vector<bool> used(u.size());
  for (int i = 0; i < t.size(); i++) {
    if (used[i]) continue;
    int c = 0;
    bool all = true;
    for (int j = i; !used[j]; (j += t.size(), j %= u.size())) {
      used[j] = true;
      if (ok[j]) {
        c++;
        ans = max(ans, c);
      } else {
        all = false;
        c = 0;
      }
    }
    if (all) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
