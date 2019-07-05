#include <bits/stdc++.h>

using namespace std;

class G {
public:
  vector<vector<int>> p, inv, sp, sinv;
  int n, m;
  vector<int> b, c, depth;
  vector<bool> a;

  G(int nn, vector<vector<int>> &np, vector<vector<int>> &ninv) {
    n = nn;
    p = np;
    inv = ninv;
    a.resize(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
      c[i] = -1;
    }
  }

  void dfs(int i) {
    if (a[i])
      return;
    a[i] = true;
    for (int j = 0; j < p[i].size(); j++) {
      if (a[p[i][j]]) {
        continue;
      }
      dfs(p[i][j]);
    }
    b.push_back(i);
  }

  void dfs2(int i, int id) {
    if (c[i] > -1)
      return;
    c[i] = id;
    for (int j = 0; j < inv[i].size(); j++) {
      if (c[inv[i][j]] > -1)
        continue;
      dfs2(inv[i][j], id);
    }
  }

  void solve() {
    for (int i = 0; i < n; i++) {
      dfs(i);
    }
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (c[b[i]] > -1)
        continue;
      dfs2(b[i], j++);
    }
    m = j;
    sp.resize(m);
    sinv.resize(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p[i].size(); j++) {
        if (c[i] == c[p[i][j]])
          continue;
        sp[c[i]].push_back(c[p[i][j]]);
        sinv[c[p[i][j]]].push_back(c[i]);
      }
    }
  }
};

struct SAT {
  int n;
  vector<pair<int, int>> conjs;

  SAT() {
    n = 0;
  }

  // a \/ b
  void add_or(int a, int b) {
    add_impl(-a, b);
    add_impl(-b, a);
  }

  // a /\ b
  void add_and(int a, int b) {
    add_impl(a, a);
    add_impl(b, b);
  }

  // a
  void add_lit(int a) {
    add_impl(a, a);
  }

  // a ^ b
  void add_xor(int a, int b) {
    add_or(a, b);
    add_or(-a, -b);
  }

  // a => b
  void add_impl(int a, int b) {
    n = max(n, max(abs(a), abs(b)));
    conjs.emplace_back(a, b);
  }

  // not(a \/ b)
  void add_nor(int a, int b) {
    add_and(-a, -b);
  }

  int f(int a) {
    assert(a != 0);
    if (a > 0) return a - 1;
    else return n + abs(a) - 1;
  }

  bool solve() {
    vector<vector<int>> p(2 * n), inv(2 * n);
    for (auto &c : conjs) {
      p[f(c.first)].push_back(f(c.second));
      inv[f(c.second)].push_back(f(c.first));
    }

    G g(2 * n, p, inv);
    g.solve();
    bool ok = true;
    for (int i = 0; i < n; i++) if (g.c[i] == g.c[i + n]) ok = false;
    return ok;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    r[i]++;
  }
  SAT solver;

  // p_1, .., p_2n : 左右
  vector<int> mp(2 * n);
  for (int i = 0; i < n; i++) {
    mp[2 * i] = i + 1;
    mp[2 * i + 1] = -(i + 1);
  }
  vector<pair<int, int>> ps(2 * n);
  for (int i = 0; i < n; i++) {
    ps[i * 2] = make_pair(l[i], r[i]);
    ps[i * 2 + 1] = make_pair(m - r[i], m - l[i]);
  }
  for (int i = 0; i < n * 2; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      if (i / 2 == j / 2) continue;
      if (!(ps[i].second <= ps[j].first || ps[j].second <= ps[i].first)) {
        solver.add_or(-mp[i], -mp[j]);
      }
    }
  }

  if (solver.solve()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
