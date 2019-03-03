#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

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
    for (ap = p[a]; ap != p[ap]; ap = p[ap])
      ;
    for (bp = p[b]; bp != p[bp]; bp = p[bp])
      ;
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
    for (ap = a; ap != p[ap]; ap = p[ap])
      ;
    return s[ap];
  }
  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap])
      ;
    return p[ap];
  }
  bool query(int a, int b) { return parent(a) == parent(b); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<pair<int, int>> ps(m);
  for (int i = 0; i < m; i++) {
    cin >> ps[i].first >> ps[i].second;
    ps[i].first--;
    ps[i].second--;
  }
  vll ans(m + 1);
  ll b = n * (n - 1) / 2;
  ans[m] = b;
  U u(n);
  for (int i = m - 1; i >= 0; i--) {
    if (u.query(ps[i].first, ps[i].second)) {
      ans[i] = b;
    } else {
      ll l = u.q(ps[i].first), r = u.q(ps[i].second);
      b -= l * r;
      u.connect(ps[i].first, ps[i].second);
      ans[i] = b;
    }
  }
  for (int i = 0; i < m; i++)
    cout << ans[i + 1] << endl;
  return 0;
}
