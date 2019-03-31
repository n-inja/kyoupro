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

using namespace std;

int main() {
  double r, s;
  int n, m;
  cin >> r >> n >> m;
  double ans = 0;
  s = 2.0 * r / n;
  vector<double> cut(n + 1);
  for(int i = 0; i < n + 1; i++) cut[i] = 2.0 * sqrt(r * r - min(r - i * s, r - (n - i) * s) * min(r - i * s, r - (n - i) * s));
  cut[0] = 0.0;
  cut[n] = 0.0;
  for(int i = 0; i < n + m; i++) {
    int j = i - m;
    if(j < 0 || j > n) {
      ans += cut[i];
      continue;
    }
    if(i < 0 || i > n) {
      ans += cut[j];
      continue;
    }
    ans += max(cut[i], cut[j]);
  }
  printf("%.9lf\n", ans);
  return 0;
}
