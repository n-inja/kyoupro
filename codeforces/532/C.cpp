#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  double _M_PI = 3.141592653589793238462643383279;
  double r;
  int n;
  cin >> n >> r;
  printf("%.12lf\n", sin(_M_PI / n) * r / (1. - sin(_M_PI / n)));
  return 0;
}
