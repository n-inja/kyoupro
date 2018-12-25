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
const double MPI = 3.14159265358979323846;
const double onehundred = 100.00000000000;

using namespace std;

double f(double a, double b, double c, double t) {
  return a * t + b * sin(c * t * MPI);
}

double aabs(double x) {
  return ((x > 0) ? x : -x);
}

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double rmin = 0.0, rmax = 100.0;

  for(double i = 0.0; i <= 200.0; i += 0.001) {
    if(f(a, b, c, i) < onehundred) continue;
    else {
      rmax = i;
      break;
    }
  }
  while((aabs(f(a, b, c, (rmin + rmax) / 2) - onehundred)) > 0.00000000001) {
    if(f(a, b, c, (rmin + rmax) / 2) > onehundred) rmax = (rmin + rmax) / 2;
    else rmin = (rmin + rmax) / 2;
  }
  printf("%.9lf\n", (rmax + rmin) / 2);
  return 0;
}
