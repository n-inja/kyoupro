#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

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
      if (c[b[i]] >= 0)
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

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<int, int> mp;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = c++;
    }
  }

  vector<vector<int>> p(c), pinv(c);
  vector<set<int>> ps(c);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      continue;
    ps[mp[a[i - 1]]].insert(mp[a[i]]);
  }
  for (int i = 0; i < c; i++) {
    for (auto &j : ps[i]) {
      p[i].push_back(j);
      pinv[j].push_back(i);
    }
  }

  G g(c, p, pinv);
  g.solve();
  long long P = 998244353;
  long long ans = 1;
  for (int i = 1; i < g.sp.size(); i++) {
    ans *= 2;
    ans %= P;
  }

  cout << ans << endl;
  return 0;
}
