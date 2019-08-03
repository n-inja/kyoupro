#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

class G {
public:
  vector<vector<int>> p, inv;
  vector<int> msize;
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
    msize.resize(m);
    for (int i = 0; i < n; i++) {
      msize[c[i]]++;
    }
  }

  bool is_singleton(int i) {
    return msize[c[i]] == 1;
  }
};

ll solve(int n, vector<bool> &ng, vector<vector<int>> &p) {
  vector<vector<int>> inv(n);
  vector<int> resolved(n);
  for (int i = 0; i < n; i++) for (auto &j : p[i]) inv[j].push_back(i);
  G g(n, p, inv);
  g.solve();
  ll ret = 0;

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (!g.is_singleton(i)) ng[i] = true;
    if (ng[i]) continue;
    if (inv[i].size() == 0) q.push(i);
  }
  while (q.size()) {
    int now = q.front();
    q.pop();
    if (ng[now]) continue;
    ng[now] = true;
    ret++;
    for (auto &j : p[now]) {
      if (ng[j]) continue;
      resolved[j]++;
      if (resolved[j] == inv[j].size()) q.push(j);
    }
  }

  return ret;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a;
  vector<pair<int, int>> aps(a);
  for (int i = 0; i < a; i++) cin >> aps[i].first >> aps[i].second;
  cin >> b;
  vector<pair<int, int>> bps(b);
  for (int i = 0; i < b; i++) cin >> bps[i].first >> bps[i].second;

  ll ans = 0;
  for (int i = 0; i < (1 << b); i++) {
    vector<vector<int>> p(n);
    vector<bool> ng(n);
    for (int j = 0; j < a; j++) p[aps[j].second - 1].push_back(aps[j].first - 1);
    for (int j = 0; j < b; j++) {
      if ((i >> j) & 1) ng[bps[j].first - 1] = true;
      else p[bps[j].first - 1].push_back(bps[j].second - 1);
    }
    ans = max(ans, solve(n, ng, p));
  }
  cout << ans << endl;
  return 0;
}
