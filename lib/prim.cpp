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

class P {
public:
  int t, f;
  long long d;

  P(int _t, int _f, long long _d) {
    t = _t;
    f = _f;
    d = _d;
  }

  bool operator<(const P &rhs) const {
    return this->d < rhs.d;
  }

  bool operator>(const P &rhs) const {
    return this->d > rhs.d;
  }
};

class Prim {
public:
  int n;
  multiset<P> p, ans;
  vector<int> parent;

  Prim(int _n, multiset<P> _p) {
    n = _n;
    p = _p;
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  multiset<P> solve() {
    ans.clear();
    while (ans.size() < n - 1 && p.size() > 0) {
      P path = *p.begin();
      p.erase(p.begin());
      int ip, jp;
      for (ip = path.f; ip != parent[ip]; ip = parent[ip]);
      for (jp = path.t; jp != parent[jp]; jp = parent[jp]);
      if (ip == jp) continue;
      int par = min(ip, jp);
      set<int> mod;
      for (ip = path.f; ip != parent[ip];) {
        mod.insert(ip);
        ip = parent[ip];
      }
      mod.insert(ip);
      for (jp = path.t; jp != parent[jp];) {
        mod.insert(jp);
        jp = parent[jp];
      }
      mod.insert(jp);
      for (auto it = mod.begin(); it != mod.end(); it++) parent[*it] = par;
      ans.insert(path);
    }
    return ans;
  }
};
