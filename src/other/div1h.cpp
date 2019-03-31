#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Edge {
  int a, b;
  int cost;
};

struct Node {
  int now, time;
  int walk;
};

bool operator<(const Node &lhs, const Node &rhs) { return lhs.time < rhs.time; }

int main() {
  while (true) {
    int n, m, l, k, a, h;
    cin >> n >> m >> l >> k >> a >> h;
    if (n == 0)
      break;
    // n: 街の数, m: 再冷凍までの時間, l: 冷凍施設のある
    // k: 辺数, a: 本国の首都, h: お姫様
    vector<int> f(l);
    for (int i = 0; i < l; i++)
      cin >> f[i];
    vector<bool> fre(n);
    for (int i = 0; i < l; i++)
      fre[f[i]] = true;
    vector<Edge> e(k);
    for (int i = 0; i < k; i++)
      cin >> e[i].a >> e[i].b >> e[i].cost;
    int path[201][201] = {};
    for (int i = 0; i < 201; i++)
      for (int j = 0; j < 201; j++)
        path[i][j] = 100000000;

    for (int i = 0; i < k; i++) {
      path[e[i].a][e[i].b] = path[e[i].b][e[i].a] = e[i].cost;
    }
    multiset<Node> q;
    q.insert(Node{a, 0, 0});
    bool ch[201][101] = {false};
    bool ok = false;
    int ans = 1000000000;
    while (q.size() > 0) {
      Node now = *q.begin();
      q.erase(q.begin());
      if (ch[now.now][now.walk]) {
        continue;
      }
      ch[now.now][now.walk] = true;
      if (now.now == h) {
        ans = min(ans, now.time + max(now.time - m, 0));
        ok = true;
        break;
      }
      if (now.walk > 0 && fre[now.now]) {
        Node next{now.now, now.time, 0};
        q.insert(next);
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (path[now.now][i] < 100000000) {
          if (now.walk + path[now.now][i] > m)
            continue;

          if (ch[i][now.walk])
            continue;
          q.insert(Node{i, now.time + path[now.now][i],
                        now.walk + path[now.now][i]});
        }
      }
    }
    if (!ok) {
      cout << "Help!" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
