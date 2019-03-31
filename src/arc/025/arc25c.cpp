#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int now;
  long long d;
  bool rab;
};

bool operator<(const Node &lhs, const Node &rhs) {
  if (lhs.d == rhs.d) {
    return lhs.rab;
  }
  return lhs.d < rhs.d;
}

int main() {
  int n, m, r, t;
  cin >> n >> m >> r >> t;
  vector<vector<pair<int, long long>>> p(n);
  for (int i = 0; i < m; i++) {
    int to, from, cost;
    cin >> from >> to >> cost;
    from--;
    to--;
    p[from].push_back(make_pair(to, cost));
    p[to].push_back(make_pair(from, cost));
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    multiset<Node> q;
    Node start{i, 0, true};
    q.insert(start);
    start.rab = false;
    q.insert(start);
    vector<bool> kam(n), rab(n);
    long long rabCnt = n;
    while (q.size() > 0) {
      Node now = *q.begin();
      q.erase(q.begin());
      if (now.rab) {
        if (rab[now.now])
          continue;
        rab[now.now] = true;
        rabCnt--;
        if (rabCnt == 0)
          break;
      } else {
        if (kam[now.now])
          continue;
        kam[now.now] = true;
      }
      if (!now.rab && now.now != i) {
        ans += rabCnt;
        if (!rab[now.now])
          ans--;
      }
      for (int j = 0; j < p[now.now].size(); j++) {
        if (now.rab && rab[p[now.now][j].first])
          continue;
        if (!now.rab && kam[p[now.now][j].first])
          continue;
        Node next{p[now.now][j].first, now.d, now.rab};
        if (now.rab)
          next.d += p[now.now][j].second * t;
        else
          next.d += p[now.now][j].second * r;
        q.insert(next);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
