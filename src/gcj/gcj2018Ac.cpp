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

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    long long n;
    double p;
    cin >> n >> p;
    vector<double> w(n), h(n);
    for (int i = 0; i < n; i++)
      cin >> w[i] >> h[i];

    double rangemin = min(w[0] * 2, h[0] * 2);
    double rangemax = sqrt(w[0] * w[0] + h[0] * h[0]) * 2;
    double sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
      sum += w[i] * 2 + h[i] * 2;

    for (int i = 1; i <= n; i++) {
      double ssum = sum;
      if ((p - sum) / i >= rangemax) {
        for (int j = 0; j < i; j++)
          ssum += rangemax;
      } else if ((p - sum) / i >= rangemin) {
        ssum = p;
      } else {
        for (int j = 0; j < i && ssum + rangemin < p; j++) {
          ssum += rangemin;
        }
      }
      ans = max(ans, ssum);
    }

    printf("Case #%d: %.7f\n", k + 1, ans);
  }
  return 0;
}
