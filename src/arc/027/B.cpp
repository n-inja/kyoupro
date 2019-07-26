#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

class U {
public:
  int n;
  vector<int> p, s;

  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  bool connect(int a, int b) {
    int ap, bp;
    for (ap = p[a]; ap != p[ap]; ap = p[ap]);
    for (bp = p[b]; bp != p[bp]; bp = p[bp]);
    if (ap == bp)
      return true;
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    s[mi] += s[ma];
    s[ma] = 0;
    for (int pp = a; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    for (int pp = b; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    return false;
  }

  int q(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return s[ap];
  }

  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return p[ap];
  }

  bool query(int a, int b) { return parent(a) == parent(b); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  U uf(256);
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<bool> used(26);
  set<char> st;
  for (char c = '0'; c < '9'; c++) uf.connect(c, c + 1);
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) uf.connect(s[i], t[i]);
    st.insert(s[i]);
    st.insert(t[i]);
  }
  ll ans = 1;
  for (auto &c : st) {
    if (used[uf.parent(c)]) continue;
    used[uf.parent(c)] = true;
    if (uf.query(c, '0')) continue;
    if (uf.query(s[0], c) || uf.query(t[0], c)) ans *= 9;
    else ans *= 10;
  }
  cout << ans << endl;
  return 0;
}
