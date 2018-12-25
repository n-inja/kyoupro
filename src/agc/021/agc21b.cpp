#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<double, double>> ps(n);
  pair<double, double> g = make_pair(0, 0);
  for (int i = 0; i < n; i++)
    cin >> ps[i].first >> ps[i].second;
  for (int i = 0; i < n; i++) {
    g.first += ps[i].first;
    g.second += ps[i].second;
  }
  g.first /= n;
  g.second /= n;
  for (int i = 0; i < n; i++) {
    ps[i].first -= g.first;
    ps[i].second -= g.second;
  }
  vector<double> ans(n);
  long long m = 1000000;
  for (int i = 0; i < m; i++) {
    double x = cos(M_PI * i * 2 / m), y = sin(M_PI * i * 2 / m);
    int id = 0;
    double maxV = -1145141919;
    for (int j = 0; j < n; j++) {
      double val = x * ps[j].first + y * ps[j].second;
      if (maxV < val) {
        maxV = val;
        id = j;
      }
    }
    ans[id] += 1;
  }
  for (int i = 0; i < n; i++) {
    printf("%.6lf\n", ans[i] / m);
  }
  return 0;
}
