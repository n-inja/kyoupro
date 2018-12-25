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
  int d, g;
  long long ans = 100000000000;
  cin >> d >> g;
  g /= 100;
  vector<pair<int, int>> ps(d);
  for (int i = 0; i < d; i++)
    cin >> ps[i].first >> ps[i].second;
  for (int i = 0; i < (1 << d); i++) {
    long long sum = 0, b = 0;
    for (int j = 0; j < d; j++) {
      if ((i >> j) & 1) {
        sum += ps[j].first;
        b += ps[j].first * (j + 1) + ps[j].second / 100;
      }
    }
    for (int j = d - 1; j >= 0 && g > b; j--) {
      if ((i >> j) & 1)
        continue;
      for (int k = 0; k < ps[j].first && g > b; k++) {
        sum += 1;
        b += j + 1;
      }
    }
    if (b >= g) {
      ans = min(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
