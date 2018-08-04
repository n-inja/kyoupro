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

struct P {
  int to, from;
  long long yen, snu;
};

struct N {
  int now;
  long long cost;
};
bool operator<(const N &lhs, const N &rhs) { return lhs.cost < rhs.cost; }

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;
  vector<vector<P>> p(n), inv(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    long long a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    p[u].push_back(P{v, u, a, b});
    p[v].push_back(P{u, v, a, b});
  }
  vector<long long> minSnu(n);
  for (int i = 0; i < n; i++)
    minSnu[i] = -1;
  multiset<N> q;
  q.insert(N{t, 0});
  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (minSnu[now.now] >= 0)
      continue;
    minSnu[now.now] = now.cost;
    for (int i = 0; i < p[now.now].size(); i++) {
      if (minSnu[p[now.now][i].to] >= 0)
        continue;
      q.insert(N{p[now.now][i].to, now.cost + p[now.now][i].snu});
    }
  }
  vector<long long> ans(n);
  q.clear();
  q.insert(N{s, 0});
  long long minC = -1;
  vector<long long> dist(n);
  for (int i = 0; i < n; i++)
    dist[i] = -1;
  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (dist[now.now] >= 0)
      continue;
    dist[now.now] = now.cost;
    for (int i = 0; i < p[now.now].size(); i++) {
      if (dist[p[now.now][i].to] >= 0)
        continue;
      q.insert(N{p[now.now][i].to, now.cost + p[now.now][i].yen});
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (minC < 0) {
      minC = minSnu[i] + dist[i];
    } else {
      minC = min(minC, minSnu[i] + dist[i]);
    }
    ans[i] = 1000000000000000ll - minC;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << endl;

  return 0;
}
