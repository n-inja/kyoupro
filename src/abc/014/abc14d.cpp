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

#define P 1000000007

using namespace std;

class LCA {
public:
  vector<vector<int>> p, parent;
  vector<int> d;
  int n;
  vector<bool> b;
  void dfs(int id, int dep, int from) {
    if(b[id]) return;
    b[id] = true;
    d[id] = dep;
    parent[0][id] = from;
    for(int i = 0; i < p[id].size(); i++) {
      if(b[p[id][i]]) continue;
      dfs(p[id][i], dep + 1, id);
    }
  }
  LCA(int _, vector<vector<int>> __) {
    n = _;
    p = __;
    b.resize(n);
    d.resize(n);
    parent.push_back(vector<int>(n));
    dfs(0, 0, 0);
    for(int i = 1; i < 20; i++) {
      parent.push_back(vector<int>(n));
      for(int j = 0; j < n; j++) parent[i][j] = parent[i - 1][parent[i - 1][j]];
    }
  }
  int query(int a, int b) {
    if(d[a] > d[b]) swap(a, b);
    if(a == 0) return d[b];
    int k = d[b] - d[a];
    int aa = b;
    for(int i = 0; i < 20; i++) if(((k >> i) & 1) > 0) aa = parent[i][aa];
    if(a == aa) return d[b] - d[a];
    int mi = 0, ma = n;
    while(ma - mi > 1) {
      int piv = (mi + ma) / 2;
      int pa = a, paa = aa;
      for(int i = 0; i < 20; i++) if(((piv >> i) & 1) > 0) pa = parent[i][pa];
      for(int i = 0; i < 20; i++) if(((piv >> i) & 1) > 0) paa = parent[i][paa];
      if(pa == paa) ma = piv;
      else mi = piv;
    }
    int par = a;
    for(int i = 0; i < 20; i++) if(((ma >> i) & 1) > 0) par = parent[i][par];
    return d[a] + d[b] - 2 * d[par];
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> p(n);
  for(int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    p[x].push_back(y);
    p[y].push_back(x);
  }
  LCA lca(n, p);
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << lca.query(a, b) + 1 << endl;
  }
  return 0;
}
