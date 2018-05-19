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

long double dist(pair<long double, long double> p1,
                 pair<long double, long double> p2) {
  long double ret = (p1.first - p2.first) * (p1.first - p2.first) +
                    (p1.second - p2.second) * (p1.second - p2.second);
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<pair<long double, long double>> aps(n), bps(n);
  for (int i = 0; i < n; i++)
    cin >> aps[i].first >> aps[i].second;
  for (int i = 0; i < n; i++)
    cin >> bps[i].first >> bps[i].second;
  pair<long double, long double> ag, bg;
  for (int i = 0; i < n; i++)
    ag.first += aps[i].first / n;
  for (int i = 0; i < n; i++)
    ag.second += aps[i].second / n;
  for (int i = 0; i < n; i++)
    bg.first += bps[i].first / n;
  for (int i = 0; i < n; i++)
    bg.second += bps[i].second / n;

  long double aMaxDist = 0, bMaxDist = 0;
  long double aMinDist = 10000000000.0f, bMinDist = 10000000000.0f;
  for (int i = 0; i < n; i++) {
    if (aMaxDist < dist(ag, aps[i])) {
      aMaxDist = dist(ag, aps[i]);
    }
    if (aMinDist > dist(ag, aps[i])) {
      aMinDist = dist(ag, aps[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (bMaxDist < dist(bg, bps[i])) {
      bMaxDist = dist(bg, bps[i]);
    }
    if (bMinDist > dist(bg, bps[i])) {
      bMinDist = dist(bg, bps[i]);
    }
  }
  long double pp = bMaxDist / aMaxDist;
  double p = sqrt(pp);
  printf("%.9lf\n", p);
  return 0;
}
