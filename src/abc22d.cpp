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

const long long PRIME = 1000000007;

using namespace std;

double f(double a, double b) {
  return a*a + b*b;
}

int main() {
  int n;
  cin >> n;
  vector<pair<double, double>> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
  for(int i=0; i<n; i++) cin >> b[i].first >> b[i].second;
  pair<double, double> ga, gb;
  for(int i=0; i<n; i++) {
    ga.first+=a[i].first/n;
    ga.second+=a[i].second/n;
    gb.first+=b[i].first/n;
    gb.second+=b[i].second/n;
  }
  double na = 0, nb = 0;
  for(int i=0; i<n; i++) {
    na = max(na, sqrt(f(a[i].first-ga.first, a[i].second-ga.second)));
    nb = max(nb, sqrt(f(b[i].first-gb.first, b[i].second-gb.second)));
  }
  printf("%.9lf\n", nb/na);
  return 0;
}
