#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
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
  int x, y, i;
};

struct P {
  int cost, i, j;
};

bool operator<(const P &lhs, const P &rhs) { return lhs.cost < rhs.cost; }

int main() {
  int n;
  cin >> n;
  vector<N> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
    v[i].i = i;
  }
  multiset<P> q;
  sort(v.begin(), v.end(),
       [](const N &lhs, const N &rhs) { return lhs.x < rhs.x; });
  for (int i = 1; i < n; i++) {
    q.insert(P{v[i].x - v[i - 1].x, v[i - 1].i, v[i].i});
  }
  sort(v.begin(), v.end(),
       [](const N &lhs, const N &rhs) { return lhs.y < rhs.y; });
  for (int i = 1; i < n; i++) {
    q.insert(P{v[i].y - v[i - 1].y, v[i - 1].i, v[i].i});
  }
  U u(n);
  int ans = 0, c = 0;
  while (c < n - 1) {
    P top = *q.begin();
    q.erase(q.begin());
    if (!u.connect(top.i, top.j)) {
      c++;
      ans += top.cost;
    }
  }
  cout << ans << endl;
  return 0;
}
