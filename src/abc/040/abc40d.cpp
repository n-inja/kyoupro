#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

using namespace std;

typedef struct {
  int time, to, from, i;
} Data;

bool operator<(const Data &lhs, const Data &rhs) {
  return lhs.time > rhs.time;
}

bool operator>(const Data &lhs, const Data &rhs) {
  return lhs.time < rhs.time;
}

class U {
public:
  int n;
  vector<int> p, s;
  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }
  void c(int a, int b) {
    int ap, bp;
    for(ap = p[a]; ap != p[ap]; ap = p[ap]);
    for(bp = p[b]; bp != p[bp]; bp = p[bp]);
    if(ap == bp) return;
    int mi = min(ap, bp), ma = max(ap, bp);
    p[ma] = mi;
    s[mi] += s[ma];
    s[ma] = 0;
    for(int pp = a; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
    for(int pp = b; pp != mi;) {
      int next = p[pp];
      p[pp] = mi;
      pp = next;
    }
  }
  int q(int a) {
    int ap;
    for(ap = a; ap != p[ap]; ap = p[ap]);
    return s[ap];
  }
};

int main() {
  int n, m, q;
  cin >> n >> m;
  vector<Data> br(m);
  for(int i = 0; i < m; i++) {
    cin >> br[i].to >> br[i].from >> br[i].time;
    br[i].to--;
    br[i].from--;
  }
  cin >> q;
  vector<Data> pr(q);
  for(int i = 0; i < q; i++) {
    cin >> pr[i].from >> pr[i].time;
    pr[i].from--;
    pr[i].i = i;
  }
  sort(br.begin(), br.end());
  sort(pr.begin(), pr.end());
  int bi = 0, pi = 0;
  vector<int> ans(q);
  U u(n);
  for(int i = 0; i < m + q; i++) {
    if(bi == m) {
      ans[pr[pi].i] = u.q(pr[pi].from);
      pi++;
      continue;
    }
    if(pi == q) {
      u.c(br[bi].to, br[bi].from);
      bi++;
      continue;
    }
    if(br[bi].time <= pr[pi].time) {
      ans[pr[pi].i] = u.q(pr[pi].from);
      pi++;
    } else {
      u.c(br[bi].to, br[bi].from);
      bi++;
    }
  }
  for(int i = 0; i < q; i++) cout << ans[i] << endl;

  return 0;
}
