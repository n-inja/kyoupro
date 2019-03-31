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
int n, m;
vector<pair<double, double>> p;
vector<double> d;

double g(pair<double, double> p1, pair<double, double> p2) {
  return (p1.first - p2.first) * (p1.first - p2.first) +
         (p1.second - p2.second) * (p1.second - p2.second);
}

bool f(double x) {
  for (int j = n; j < n + m; j++) {
    for (int i = 0; i < n + m; i++) {
      if (i == j)
        continue;
      if (sqrt(g(p[j], p[i])) < x + (i >= n ? x : d[i]))
        return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  p.resize(n + m);
  d.resize(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second >> d[i];
  for (int i = n; i < n + m; i++)
    cin >> p[i].first >> p[i].second;
  if (m == 0) {
    double ans = d[0];
    for (int i = 1; i < n; i++)
      ans = min(ans, d[i]);
    printf("%.9f\n", ans);
    return 0;
  }
  double minx = 0, maxx = 10000000000;
  for (int i = 0; i < 1000; i++) {
    double mm = (minx + maxx) / 2;
    if (f(mm))
      minx = mm;
    else
      maxx = mm;
  }
  printf("%.9f\n", minx);
  return 0;
}
