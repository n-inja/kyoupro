#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

#define P 1000000007

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> t(n), v(n + 1);
  for(int i = 0; i < n; i++) cin >> t[i];
  for(int i = 0; i < n; i++) cin >> v[i];
  v[n] = 0;
  double ans = 0, spd = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(v[i] > spd + t[i]) v[i] = spd + t[i];
    spd = v[i];
  }
  spd = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] - spd + max(v[i] - v[i + 1], 0.0) < t[i]) {
      ans += (t[i] - v[i] + spd - max(v[i] - v[i + 1], 0.0)) * v[i];
      ans += (v[i] - spd) * (spd + v[i]) / 2;
      ans += max(v[i] - v[i + 1], 0.0) * (v[i] + min(v[i], v[i + 1])) / 2;
      spd = min(v[i + 1], v[i]);
    } else {
      if(spd + t[i] < v[i + 1]) {
        ans += t[i] * t[i] / 2;
        ans += t[i] * spd;
        spd += t[i];
      } else {
        double x = (t[i] + v[i + 1] - spd) / 2, y = spd + x;
        ans += x * (spd + y) / 2;
        ans += (t[i] - x) * (y + v[i + 1]) / 2;
        spd = v[i + 1];
      }
    }
  }
  printf("%.9lf\n", ans);
  return 0;
}
