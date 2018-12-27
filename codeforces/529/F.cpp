#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

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

struct N {
  int t, f;
  long long c;
};

bool operator<(const N &l, const N &r) { return l.c < r.c; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int minid = 0;
  for (int i = 0; i < n; i++) {
    if (a[minid] > a[i])
      minid = i;
  }
  vector<N> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].t >> v[i].f >> v[i].c;
    v[i].t--;
    v[i].f--;
  }
  for (int i = 0; i < n; i++) {
    if (i == minid)
      continue;
    v.push_back(N{minid, i, a[minid] + a[i]});
  }
  sort(v.begin(), v.end());
  U u(n);
  long long ans = 0;
  for (auto &m : v) {
    if (!u.connect(m.t, m.f)) {
      ans += m.c;
    }
  }
  cout << ans << endl;

  return 0;
}
