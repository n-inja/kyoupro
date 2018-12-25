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

const long long PRIME = 1000000007;

using namespace std;

class Node {
public:
  int now, id, d;
  Node(int n, int i, int d_) {
    now = n;
    id = i;
    d = d_;
  }
  bool operator<(const Node &rhs) const {
    return this->d < rhs.d;
  }
  bool operator>(const Node &rhs) const {
    return this->d > rhs.d;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n), cost(n);
  vector<vector<int>> p(n), l(n), id(n);
  for(int i = 0; i < m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    u--; v--;
    p[u].push_back(v);
    p[v].push_back(u);
    l[u].push_back(d);
    l[v].push_back(d);
  }
  c[0] = 1;
  multiset<Node> q;
  for(int i = 0; i < p[0].size(); i++) {
    q.insert(Node(p[0][i], i + 1, l[0][i]));
  }
  int ans = 1000000000;
  while(q.size() > 0) {
    Node node = *q.begin();
    q.erase(q.begin());
    if(c[node.now] == node.id) continue;
//    cout << node.now << " " << node.id << " " << node.d << endl;
    if(c[node.now] == 0) {
      c[node.now] = node.id;
      cost[node.now] = node.d;
      for(int i = 0; i < p[node.now].size(); i++) {
        if(c[p[node.now][i]] == node.id || p[node.now][i] == 0) continue;
        q.insert(Node(p[node.now][i], node.id, node.d + l[node.now][i]));
      }
    } else {
      ans = min(ans, cost[node.now] + node.d);
    }
  }
  if(ans == 1000000000) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
