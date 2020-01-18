#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int u, v, i, flip;
  ll du, dv, c;
  bool use;
};

bool operator<(const N &l, const N &r) {
  if (min(l.du, l.dv) == min(r.du, r.dv)) {
    return max(l.du, l.dv) < max(r.du, r.dv);
  }
  return min(l.du, l.dv) < min(r.du, r.dv);
}

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
    for (ap = p[a]; ap != p[ap]; ap = p[ap]);
    for (bp = p[b]; bp != p[bp]; bp = p[bp]);
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
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return s[ap];
  }

  int parent(int a) {
    int ap;
    for (ap = a; ap != p[ap]; ap = p[ap]);
    return p[ap];
  }

  bool query(int a, int b) { return parent(a) == parent(b); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  vector<N> ns(m);
  for (int i = 0; i < m; i++) cin >> ns[i].u >> ns[i].v;
  for (int i = 0; i < m; i++) {
    ns[i].u--;
    ns[i].v--;
    ns[i].i = i;
    ns[i].c = 0;
    ns[i].flip = false;
    ns[i].du = d[ns[i].u];
    ns[i].dv = d[ns[i].v];
  }
  sort(ns.begin(), ns.end());
  vector<int> type(n, -1);
  vector<bool> ok(n);
  ll INF = 1000000000;

  for (int i = 0; i < m; i++) {
    if (ns[i].du == ns[i].dv) {
      if (!ok[ns[i].u] || !ok[ns[i].v]) {
        ns[i].c = ns[i].du;
        ns[i].flip = 1;
        ok[ns[i].u] = ok[ns[i].v] = true;
      } else {
        ns[i].c = INF;
        ns[i].flip = 0;
      }
    } else {
      if (ns[i].du < ns[i].dv) {
        if (!ok[ns[i].u]) {
          cout << -1 << endl;
          return 0;
        }
        ok[ns[i].v] = true;
        ns[i].c = ns[i].dv - ns[i].du;
        ns[i].flip = 0;
      } else {
        if (!ok[ns[i].v]) {
          cout << -1 << endl;
          return 0;
        }
        ok[ns[i].u] = true;
        ns[i].c = ns[i].du - ns[i].dv;
        ns[i].flip = 0;
      }
    }
  }
  vector<vector<pair<int, bool>>> p(n);
  U uf(n);
  for (int i = 0; i < m; i++) {
    if (uf.connect(ns[i].u, ns[i].v)) {
      ns[i].c = INF;
    } else {
      p[ns[i].u].emplace_back(ns[i].v, ns[i].flip);
      p[ns[i].v].emplace_back(ns[i].u, ns[i].flip);
    }
  }
  function<void(int, int)> dfs;
  dfs = [&](int i, int c) {
    if (type[i] >= 0) return;
    type[i] = c;
    for (auto &pr : p[i]) {
      if (type[pr.first] >= 0) continue;
      if (pr.second) {
        dfs(pr.first, 1 - c);
      } else {
        dfs(pr.first, c);
      }
    }
  };
  dfs(0, 0);

  for (int i = 0; i < n; i++) cout << "BW"[type[i]];
  cout << endl;
  vector<ll> ans(m);
  for (int i = 0; i < m; i++) {
    ans[ns[i].i] = ns[i].c;
  }
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
