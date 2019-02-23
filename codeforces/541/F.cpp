#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct N {
  int x;
  N *l, *r;
};
struct M {
  N *p;
};

class U {
public:
  int n;
  vector<int> p, s;
  vector<M> ns;
  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
      ns[i].p = new N;
      ns[i].p->x = i;
      ns[i].p->l = ns[i].p->r = NULL;
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
    N *np = new N;
    np->x = -1;
    np->l = ns[mi].p;
    np->r = ns[ma].p;
    ns[mi].p = ns[ma].p = np;
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
  void f(N *p, vector<int> &v) {
    if (p == NULL)
      return;
    if (p->l != NULL)
      f(p->l, v);
    if (p->r != NULL)
      f(p->r, v);
    if (p->x >= 0)
      v.push_back(p->x);
  }
  void g() {
    vector<int> v;
    f(ns[p[0]].p, v);
    cout << v[0] + 1;
    for (int i = 1; i < n; i++) {
      cout << " " << v[i] + 1;
    }
    cout << endl;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  U u(n);
  for (int i = 0; i < n - 1; i++) {
    int t, f;
    cin >> t >> f;
    t--;
    f--;
    u.connect(t, f);
  }
  u.g();

  return 0;
}
