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
  long long y, b, r;
  cin >> y >> b >> r;
  long long ar = r - 2;
  long long ab = b - 1;
  long long ay = y;
  long long ans = min(ar, min(ab, ay));
  cout << ans * 3 + 3 << endl;
  return 0;
}
