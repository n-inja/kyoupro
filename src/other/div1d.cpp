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

int main() {
  while (true) {
    double x, h;
    cin >> x >> h;
    if (x == 0 && h == 0)
      return 0;
    double ans = x * x;
    ans += x * sqrt(x * x / 4 + h * h) * 2;
    printf("%.9lf\n", ans);
  }

  return 0;
}
