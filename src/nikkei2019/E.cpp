#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int n, m;
vll x;
int ans;

struct N {
  int t, f;
  ll v;
};
bool operator<(const N &l, const N &r) { return l.v < r.v; }

class BIT {
public:
  int n;
  vector<int> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  // add v[a] + w
  void add(int a, int w) {
    a++;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }
  // [0, a)
  int sum(int a) {
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};
BIT bit(1 << 18);

class U {
public:
  int n;
  vector<int> p;
  vector<ll> v;
  vector<pair<ll, int>> s;
  U(vll a) {
    n = a.size();
    p.resize(n);
    s.resize(n);
    v = a;
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }
  bool connect(int a, int b, ll r) {
    int ap, bp;
    for (ap = p[a]; ap != p[ap]; ap = p[ap])
      ;
    for (bp = p[b]; bp != p[bp]; bp = p[bp])
      ;
    if (ap == bp) {
      s[ap].first = r;
      s[ap].second += 1;
      if (s[ap].first <= v[ap]) {
        bit.add(ap, -(bit.sum(ap + 1) - bit.sum(ap)));
        bit.add(ap, s[ap].second);
        ans = m - bit.sum(n);
      }
      return true;
    }
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    v[mi] += v[ma];
    v[ma] = 0;
    if (r <= v[mi]) {
      bit.add(ma, -(bit.sum(ma + 1) - bit.sum(ma)));
      bit.add(mi, -(bit.sum(mi + 1) - bit.sum(mi)));
      bit.add(mi, s[mi].second + s[ma].second + 1);
      ans = m - bit.sum(n);
    } else {
      int sa = bit.sum(ma + 1) - bit.sum(ma);
      int si = bit.sum(mi + 1) - bit.sum(mi);
      bit.add(ma, -sa);
      bit.add(mi, -si);
      bit.add(mi, sa + si);
    }
    s[mi].first = r;
    s[mi].second += s[ma].second + 1;
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
  cin >> n >> m;
  x.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  U uf(x);
  vector<N> ns(m);
  for (int i = 0; i < m; i++) {
    cin >> ns[i].t >> ns[i].f >> ns[i].v;
    ns[i].t--;
    ns[i].f--;
  }
  sort(ns.begin(), ns.end());
  ans = m;
  for (int i = 0; i < m; i++) {
    uf.connect(ns[i].t, ns[i].f, ns[i].v);
  }
  cout << ans << endl;
  return 0;
}
