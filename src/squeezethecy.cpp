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

double f(double r1, double r2) {
  if(r2 > r1) swap(r1, r2);
  return sqrt(pow(r1 + r2, 2) - pow(r2 - r1, 2));
}

int main() {
  int n;
  cin >> n;
  vector<double> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];
  vector<double> e(n);
  e[0] = d[0];
  for(int i = 1; i < n; i++) {
    double m = d[i];
    for(int j = 0; j < i; j++) {
      m = max(m, e[j] + f(d[i], d[j]));
    }
    e[i] = m;
  }
  double ans = 0;
  for(int i = 0; i < n; i++) ans = max(ans, d[i] + e[i]);
  printf("%.9f\n", ans);
  return 0;
}
