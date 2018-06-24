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

long long r, b, x, y;

bool f(long long z) {
  long long rr = r - z;
  long long bb = b - z;
  if (rr < 0 || bb < 0)
    return false;
  return rr / (x - 1) + bb / (y - 1) >= z;
}

int main() {
  cin >> r >> b >> x >> y;
  long long in = 0, ax = 1000000000000000001ll;
  while (ax - in > 1) {
    long long mm = (in + ax) / 2;
    if (f(mm)) {
      in = mm;
    } else {
      ax = mm;
    }
  }
  cout << in << endl;
  return 0;
}
