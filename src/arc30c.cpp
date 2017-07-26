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

int k;

class Node {
public:
  int now;
  string s;
  Node(int n, string str) {
    now = n;
    s = str;
  }
  bool operator>(const Node &rhs) const {
    return this->s > rhs.s;
  }
  bool operator<(const Node &rhs) const {
    return this->s < rhs.s;
  }
};

class G {
public:
  vector<vector<int>> p, inv, sp, sinv;
  int n, m, l;
  vector<string> word;
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
    l = 0;
  }
  void dfs(int i) {
    if(a[i]) return;
  //  cout << i << " " << inv[i].size() << " " << p[i].size() << endl;
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
//    for(int i = 0; i < n; i++) cout << b[i] << endl;
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
  int dfs3(int i) {
    if(depth[i] > 0) return depth[i];
    int dep = 0;
    for(int j = 0; j < sp[i].size(); j++) {
      dep = max(dep, dfs3(sp[i][j]));
    }
    depth[i] = dep + word[i].size();
    return depth[i];
  }
  void solve2(vector<char> d) {
    word.resize(m);
    for(int i = 0; i < n; i++) {
      word[c[i]].push_back(d[i]);
    }
    for(int i = 0; i < m; i++) {
      sort(word[i].begin(), word[i].end());
    }
    depth.resize(m);
    for(int i = 0; i < m; i++) {
      dfs3(i);
    }
    string s = "";
    multiset<Node> q;
    map<string, bool> f;
    for(int i = 0; i < m; i++) {
      if(sinv[i].size() == 0) {
        for(int j = word[i].size(); j >= 0 && depth[i] - word[i].size() + j >= k; j--) {
          if(!f[word[i].substr(0, j) + "a"]) {
            q.insert(Node(i, word[i].substr(0, j)));
            f[word[i].substr(0, j)] = true;
          }
        }
      }
    }
    while(q.size() > 0) {
      Node now = *q.begin();
      q.erase(q.begin());
    //  cout << now.s << endl;
      if(now.s.size() == k) {
        cout << now.s << endl;
        return;
      }
      for(int i = 0; i < sp[now.now].size(); i++) {
        for(int j = word[sp[now.now][i]].size(); j >= 0 && now.s.size() + depth[sp[now.now][i]] - word[sp[now.now][i]].size() + j >= k; j--) {
          if(!f[now.s + word[sp[now.now][i]].substr(0, j) + "a"]) {
            q.insert(Node(sp[now.now][i], now.s + word[sp[now.now][i]].substr(0, j)));
            f[now.s + word[sp[now.now][i]].substr(0, j)] = true;
          }
        }
      }
    }
    cout << -1 << endl;
    return;
  }
};

int main() {
  vector<vector<int>> path, inv;
  int n, m;
  cin >> n >> m >> k;
  path.resize(n);
  inv.resize(n);

  vector<char> c;
  c.resize(n);
  for(int i = 0; i < n; i++) cin >> c[i];
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    path[a].push_back(b);
    inv[b].push_back(a);
  }

  G graph(n, path, inv);
  graph.solve();
  graph.solve2(c);
  return 0;
}
