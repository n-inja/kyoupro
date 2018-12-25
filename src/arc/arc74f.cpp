#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

typedef struct {
  int now, from;
  int cost, flow;
} Node;

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.cost < rhs.cost;
}

class Increase {
public:
  int n, flowMax = 1000000;
  vector<vector<int>> p;
  vector<int> parent;
  Increase(int _n, vector<vector<int>> _p) {
    n = _n;
    p = _p;
    parent.resize(n);
  }
  int solve() {
    int ret = 0;
    while(true) {
      for(int i = 0; i < n; i++) parent[i] = i;
      multiset<Node> q;
      q.insert(Node{0, -1, 0, 100000});
      while(q.size() > 0) {
        Node now = *q.begin();
        q.erase(q.begin());
        if(parent[now.now] != now.now) continue;
        parent[now.now] = now.from;
        if(now.now == n - 1) break;
        for(int i = 0; i < n; i++) if(parent[i] == i && p[now.now][i] > 0) q.insert(Node{i, now.now, now.cost + 1, min(now.flow, p[now.now][i])});
      }
      if(parent[n - 1] == n - 1) break;
      int now = n - 1, flow = flowMax;
      while(parent[now] >= 0 && parent[now] != now) {
        flow = min(flow, p[parent[now]][now]);
        p[parent[now]][now]--;
        p[now][parent[now]]++;
        now = parent[now];
      }
      ret += flow;
    }
    return ret;
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for(int i = 0; i < h; i++) cin >> mp[i];

  int n = h + w + 2;
  // 0     S
  // n - 1 T
  // 1-w
  // w+1-h+w
  int sx, sy, tx, ty;
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == 'S') {
    sx = j;
    sy = i;
  } else if(mp[i][j] == 'T') {
    tx = j;
    ty = i;
  }

  vector<vector<int>> p(n);
  for(int i = 0; i < n; i++) p[i].resize(n);

  p[0][sx + 1] = 1000000;
  p[0][w + sy + 1] = 1000000;
  p[tx + 1][n - 1] = 1000000;
  p[w + ty + 1][n - 1] = 1000000;

  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == 'o') {
    p[j + 1][w + i + 1] = 1;
    p[w + i + 1][j + 1] = 1;
  }

  if(sx == tx || sy == ty) {
    cout << -1 << endl;
    return 0;
  }

  Increase inc(n, p);
  cout << inc.solve() << endl;
}
