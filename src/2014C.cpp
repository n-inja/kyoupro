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

double eq(double x) { return fabs(x) < 0.000001; }

double f(double r, double x) {
  if (fabs(x) > r)
    return -100000000;
  if (eq(fabs(x) - r))
    return -r;
  return -(r - sqrt(r * r - x * x));
}

int main() {
  while (true) {
    int r, n;
    cin >> r >> n;
    if (r == 0 && n == 0)
      break;
    double ans = 10000000000;
    vector<pair<int, int>> x(n);
    vector<int> h(n);
    for (int i = 0; i < n; i++)
      cin >> x[i].first >> x[i].second >> h[i];
    int H[50][2] = {0};
    int offset = 25;
    for (int i = 0; i < n; i++) {
      for (int j = max(-r, x[i].first); j < min(r + 1, x[i].second); j++) {
        H[j + offset][0] = max(H[j + offset][0], h[i]);
      }
      for (int j = max(-r, x[i].first + 1); j <= min(r, x[i].second); j++) {
        H[j + offset][1] = max(H[j + offset][1], h[i]);
      }
    }
    for (int i = -r; i <= r; i++) {
      if (i < r)
        ans = min(ans, H[i + offset][0] - f(r, i));
      if (i > -r)
        ans = min(ans, H[i + offset][1] - f(r, i));
    }
    printf("%.9lf\n", ans);
  }
  return 0;
}
