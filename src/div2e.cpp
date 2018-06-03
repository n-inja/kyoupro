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
  double oa, ab, bc;
  cin >> oa >> ab >> bc;
  double maxr = oa + ab + bc;
  double minr = fabs(oa + ab - bc);
  minr = min(minr, fabs(oa - ab + bc));
  minr = min(minr, fabs(oa - ab - bc));
  if (oa < ab + bc && max(ab, bc) <= oa + min(ab, bc)) {
    minr = 0;
  }
  double ans = maxr * maxr * M_PI;
  ans -= minr * minr * M_PI;
  printf("%.9lf\n", ans);
  return 0;
}
