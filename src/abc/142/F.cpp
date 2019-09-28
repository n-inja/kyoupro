#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

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

struct N {
  int i, f, d;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> p(n), inv(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    inv[b].push_back(a);
  }
  G g(n, p, inv);
  g.solve();
  if (n == g.m) {
    cout << -1 << endl;
    return 0;
  }
  vector<bool> used(n);
  vector<int> par(n, -1);

  auto bfs = [&](int i) {
    queue<N> q;
    q.push(N{i, -1, 1});
    while (q.size()) {
      auto now = q.front();
      q.pop();
      if (used[now.i]) {
        continue;
      }
      used[now.i] = true;
      par[now.i] = now.f;
      map<int, int> mp;
      vector<int> buf;
      int k = now.i;
      int c = 0;
      while (par[k] >= 0) {
        mp[k] = c;
        buf.push_back(k);
        c++;
        k = par[k];
      }
      mp[i] = c;
      buf.push_back(i);
      c++;

      vector<int> ans;
      int anssize = n * 2;
      for (auto &j : p[now.i]) {
        if (used[j]) {
          if (mp.find(j) != mp.end()) {
            vector<int> b;
            for (int k = mp[j]; k >= 0; k--) {
              b.push_back(buf[k] + 1);
            }
            if (anssize > b.size()) {
              anssize = b.size();
              ans = b;
            }
          } else {
            continue;
          }
        }
        q.push(N{j, now.i, now.d + 1});
      }
      if (anssize < 2 * n) {
        cout << anssize << endl;
        for (auto j : ans) cout << j << endl;
        return true;
      }
    }
    return false;
  };

  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    if (bfs(i)) {
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
