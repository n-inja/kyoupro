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
vector<vector<int>> p;
vector<bool> used;
vector<int> dep;

struct N {
  int d;
  int p;
};

bool operator<(const N &l, const N &r) { return l.d > r.d; }
multiset<N> q;

void dfs(int now, int from, int depth, vector<int> &v) {
  dep[now] = depth;
  v.push_back(now);
  for (auto &i : p[now]) {
    if (i == from)
      continue;
    dfs(i, now, depth + 1, v);
  }
}

void make(int now) {
  if (used[now])
    return;
  vector<int> s, t;
  dfs(now, -1, 0, s);
  int maxId = now;
  for (auto &i : s) {
    if (dep[maxId] < dep[i]) {
      maxId = i;
    }
    used[i] = true;
  }
  dfs(maxId, -1, 0, t);
  int maxId2 = maxId;
  for (auto &i : s) {
    if (dep[maxId2] < dep[i]) {
      maxId2 = i;
    }
  }
  int half = maxId2;
  while (dep[half] != dep[maxId2] / 2) {
    for (auto &i : p[half]) {
      if (dep[i] + 1 == dep[half]) {
        half = i;
        break;
      }
    }
  }
  q.insert(N{dep[maxId2] + 1, half});
}

int main() {
  int n, m;
  cin >> n >> m;
  p.resize(n);
  used.resize(n);
  dep.resize(n);
  for (int i = 0; i < m; i++) {
    int t, f;
    cin >> t >> f;
    t--;
    f--;
    p[t].push_back(f);
    p[f].push_back(t);
  }
  for (int i = 0; i < n; i++)
    make(i);
  vector<pair<int, int>> v;
  while (q.size() > 1) {
    N f = *q.begin();
    q.erase(q.begin());
    N t = *q.begin();
    q.erase(q.begin());
    if (t.d + 1 < f.d) {
      v.push_back(make_pair(f.p, t.p));
      if (f.d % 2 == 0 && f.d == t.d + 2) {
        q.insert(N{f.d + 1, f.p});
      } else {
        q.insert(N{f.d, f.p});
      }
    } else if (f.d == t.d) {
      v.push_back(make_pair(f.p, t.p));
      q.insert(N{f.d + 1 + (f.d % 2 == 0), f.p});
    } else {
      v.push_back(make_pair(f.p, t.p));
      q.insert(N{f.d + 1, f.p});
    }
  }
  cout << q.begin()->d - 1 << endl;
  for (auto &pr : v) {
    cout << pr.first + 1 << " " << pr.second + 1 << endl;
  }
  return 0;
}
