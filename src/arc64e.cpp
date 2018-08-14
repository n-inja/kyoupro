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

struct N {
  int i;
  double t;
};

bool operator<(const N &lhs, const N &rhs) { return lhs.t < rhs.t; }

double dist(pair<double, double> l, pair<double, double> r) {
  return sqrt((l.first - r.first) * (l.first - r.first) +
              (l.second - r.second) * (l.second - r.second));
}

int main() {
  double sx, sy, ex, ey;
  int n;
  cin >> sx >> sy >> ex >> ey >> n;
  vector<pair<double, double>> ps(n + 2);
  vector<double> r(n + 2);
  for (int i = 0; i < n; i++)
    cin >> ps[i].first >> ps[i].second >> r[i];
  ps[n] = make_pair(sx, sy);
  ps[n + 1] = make_pair(ex, ey);
  multiset<N> q;
  q.insert({n, 0});
  vector<bool> c(n + 2);
  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (now.i == n + 1) {
      printf("%.9lf\n", now.t);
      return 0;
    }
    if (c[now.i])
      continue;
    c[now.i] = true;
    for (int i = 0; i < n + 2; i++) {
      if (c[i])
        continue;
      q.insert({i, now.t + max(0.0, dist(ps[now.i], ps[i]) - r[now.i] - r[i])});
    }
  }
  return 0;
}
