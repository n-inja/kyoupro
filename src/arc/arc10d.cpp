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

#define P 1000000007

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

int main() {
  int n, m;
  vector<bool> b;
  vector<pair<unsigned long long, unsigned long long>> p, e;
  vector<vector<int>> path, inv;
  int ans = 0;
  cin >> n;
  p.resize(n);
  path.resize(n);
  inv.resize(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  cin >> m;
  e.resize(m);
  for(int i = 0; i < m; i++) cin >> e[i].first >> e[i].second;
  for(int i = 0; i < n; i++) {
    unsigned long long jou = 9000000000000000000;
    for(int j = 0; j < m; j++) {
      jou = min(jou, (p[i].first - e[j].first) * (p[i].first - e[j].first) + (p[i].second - e[j].second) * (p[i].second - e[j].second));
    }
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(jou > (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second)) {
        path[i].push_back(j);
        inv[j].push_back(i);
      }
    }
  }
  if(m == 0) {
    cout << 1 << endl;
    return 0;
  }

  G graph(n, path, inv);
  graph.solve();
  for(int i = 0; i < graph.m; i++) {
    if(graph.sinv[i].size() == 0) ans++;
  }

  cout << ans << endl;
  return 0;
}
