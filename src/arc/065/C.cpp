#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int x, y, i, c;
};

struct Y {
  bool operator()(const N &l, const N &r) {
    return l.y < r.y;
  }
};

bool ycomp(const N &l, const N &r) {
  return l.y < r.y;
}

struct X {
  bool operator()(const N &l, const N &r) {
    return l.x < r.x;
  }
};

bool xcomp(const N &l, const N &r) {
  return l.x < r.x;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  vector<N> ns(n);
  map<int, vector<N>> xns, yns;
  map<int, set<N, Y>> xs;
  map<int, set<N, X>> ys;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ns[i].i = i;
    ns[i].x = x + y;
    ns[i].y = x - y;
    ns[i].c = 0;
    xns[ns[i].x].push_back(ns[i]);
    yns[ns[i].y].push_back(ns[i]);
    xs[ns[i].x].insert(ns[i]);
    ys[ns[i].y].insert(ns[i]);
  }
  for (auto &v : xns) {
    sort(v.second.begin(), v.second.end(), ycomp);
  }
  for (auto &v : yns) {
    sort(v.second.begin(), v.second.end(), xcomp);
  }
  int d = max(abs(ns[a].x - ns[b].x), abs(ns[a].y - ns[b].y));

  for (int i = 0; i < n; i++) {
    if (yns.find(ns[i].y + d) != yns.end()) {
      auto &v = yns[ns[i].y + d];
      N ln, rn;
      ln.x = ns[i].x - d;
      rn.x = ns[i].x + d;
      auto lit = lower_bound(v.begin(), v.end(), ln, xcomp);
      auto rit = lower_bound(v.begin(), v.end(), rn, xcomp);
      ns[i].c += rit - lit;
    }
    if (xns.find(ns[i].x + d) != xns.end()) {
      auto &v = xns[ns[i].x + d];
      N ln, rn;
      ln.y = ns[i].y - d;
      rn.y = ns[i].y + d;
      auto lit = upper_bound(v.begin(), v.end(), ln, ycomp);
      auto rit = upper_bound(v.begin(), v.end(), rn, ycomp);
      ns[i].c += rit - lit;
    }
  }

  function<ll(int)> dfs;
  set<int> used;
  for (int i = 0; i < n; i++) used.insert(i);
  dfs = [&](int i) {
    if (used.find(i) == used.end()) return 0LL;
    used.erase(used.find(i));
    ll ret = ns[i].c;
    set<int> next;
    if (yns.find(ns[i].y + d) != yns.end()) {
      auto &v = ys[ns[i].y + d];
      N ln;
      ln.x = ns[i].x - d;
      auto lit = v.lower_bound(ln);
      while (lit != v.end() && lit->x <= ns[i].x + d) {
        if (used.find(lit->i) != used.end()) {
          next.insert(lit->i);
        }
        v.erase(lit++);
      }
    }
    if (xns.find(ns[i].x + d) != xns.end()) {
      auto &v = xs[ns[i].x + d];
      N ln;
      ln.y = ns[i].y - d;
      auto lit = v.lower_bound(ln);
      while (lit != v.end() && lit->y <= ns[i].y + d) {
        if (used.find(lit->i) != used.end()) {
          next.insert(lit->i);
        }
        v.erase(lit++);
      }
    }
    if (yns.find(ns[i].y - d) != yns.end()) {
      auto &v = ys[ns[i].y - d];
      N ln;
      ln.x = ns[i].x - d;
      auto lit = v.lower_bound(ln);
      while (lit != v.end() && lit->x <= ns[i].x + d) {
        if (used.find(lit->i) != used.end()) {
          next.insert(lit->i);
        }
        v.erase(lit++);
      }
    }
    if (xns.find(ns[i].x - d) != xns.end()) {
      auto &v = xs[ns[i].x - d];
      N ln;
      ln.y = ns[i].y - d;
      auto lit = v.lower_bound(ln);
      while (lit != v.end() && lit->y <= ns[i].y + d) {
        if (used.find(lit->i) != used.end()) {
          next.insert(lit->i);
        }
        v.erase(lit++);
      }
    }
    for (auto &j : next) {
      ret += dfs(j);
    }
    return ret;
  };
  cout << dfs(a) << endl;
  return 0;
}
