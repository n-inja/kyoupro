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
