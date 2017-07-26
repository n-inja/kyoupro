
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
    for(int i = 0; i < n; i++) {
      c[i] = -1;
    }
  }
  void dfs(int i) {
    if(a[i]) return;
    a[i] = true;
    for(int j = 0; j < p[i].size(); j++) {
      if(a[p[i][j]]) {
        continue;
      }
      dfs(p[i][j]);
    }
    b.push_back(i);
  }
  void dfs2(int i, int id) {
    if(c[i] > -1) return;
    c[i] = id;
    l++;
    for(int j = 0; j < inv[i].size(); j++) {
      if(c[inv[i][j]] > -1) continue;
      dfs2(inv[i][j], id);
    }
  }
  void solve() {
    for(int i = 0; i < n; i++) {
      dfs(i);
    }
    int j = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(c[b[i]] > 0) continue;
      dfs2(b[i], j++);
    }
    m = j;
    sp.resize(m);
    sinv.resize(m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < p[i].size(); j++) {
        if(c[i] == c[p[i][j]]) continue;
        sp[c[i]].push_back(c[p[i][j]]);
        sinv[c[p[i][j]]].push_back(c[i]);
      }
    }
  }
};
