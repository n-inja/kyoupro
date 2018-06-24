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

vector<vector<pair<int, int>>> path;
vector<vector<pair<int, int>>> sub;

struct N {
  int now, cost;
};

bool operator<(const N &lhs, const N &rhs) { return lhs.cost < rhs.cost; }

int main() {
  while (true) {
    int n;
    int sum = 0;
    cin >> n;
    path.clear();
    sub.clear();
    if (n == 0)
      break;
    path.resize(n);
    sub.resize(n);
    vector<int> P(n - 1);
    vector<int> D(n - 1);
    for (int i = 1; i < n; i++) {
      cin >> P[i - 1];
      P[i - 1]--;
    }
    for (int i = 1; i < n; i++) {
      cin >> D[i - 1];
      sum += D[i - 1];
    }
    for (int i = 0; i < n - 1; i++) {
      path[P[i]].push_back(make_pair(i + 1, D[i]));
      path[i + 1].push_back(make_pair(P[i], D[i]));
    }
    vector<bool> c(n);
    int rest = 0;
    for (int i = 0; i < n; i++) {
      if (path[i].size() == 1) {
        rest += path[i][0].second;
        c[i] = true;
      }
    }
    int subsum = sum - rest;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < path[i].size(); j++)
        if (!c[path[i][j].first] && !c[i]) {
          sub[i].push_back(path[i][j]);
        }
    }
    vector<bool> used(n);
    int id = -1;
    for (int i = 0; i < n; i++) {
      if (c[i] || used[i])
        continue;
      multiset<N> q;
      q.insert(N{i, 0});
      while (q.size() > 0) {
        N now = *q.begin();
        q.erase(q.begin());
        if (used[now.now])
          continue;
        used[now.now] = true;
        id = now.now;
        for (int j = 0; j < sub[now.now].size(); j++) {
          q.insert(N{sub[now.now][j].first, now.cost + sub[now.now][j].second});
        }
      }
      break;
    }
    int dist = 0;
    used.clear();
    used.resize(n);
    multiset<N> q;
    q.insert(N{id, 0});
    while (q.size() > 0) {
      N now = *q.begin();
      q.erase(q.begin());
      if (used[now.now])
        continue;
      used[now.now] = true;
      dist = now.cost;
      for (int j = 0; j < sub[now.now].size(); j++) {
        q.insert(N{sub[now.now][j].first, now.cost + sub[now.now][j].second});
      }
    }
    cout << dist * 2 + (subsum - dist) * 3 + rest << endl;
  }
  return 0;
}
