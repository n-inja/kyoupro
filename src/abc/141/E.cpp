#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


const int MAX_STRING_SIZE = 1000000;

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
  ll n;
  string s;
  cin >> n >> s;
  s.push_back('$');
  RHinit();
  RH rh(s);

  ll l = 0, r = n;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    vector<vector<ll>> hss;
    for (int i = 0; i < n; i++) {
      if (i + m > n) continue;
      hss.push_back(rh.substr(i, i + m));
    }
    multiset<vector<ll>> lms, rms;
    for (int i = m; i < hss.size(); i++) rms.insert(hss[i]);
    bool breaked = false;
    for (int i = 0; i < hss.size(); i++) {
      if (i >= m) {
        lms.insert(hss[i - m]);
      }
      if (rms.find(hss[i]) != rms.end()) {
        breaked = true;
        break;
      }
      if (lms.find(hss[i]) != lms.end()) {
        breaked = true;
        break;
      }
      if (i + m < hss.size())
        rms.erase(rms.find(hss[i + m]));
    }
    if (breaked) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
