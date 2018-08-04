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
  long long n, m, d;
  cin >> n >> m >> d;
  double ans = 0;
  if (d == 0) {
    ans = (n - d) * (m - 1) / ((double)n * n);
  } else {
    ans = (n - d) * (m - 1) * 2 / ((double)n * n);
  }
  printf("%.9lf\n", ans);
  return 0;
}
