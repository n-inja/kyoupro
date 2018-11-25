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
  long long x, y;
  cin >> x >> y;
  if (abs(x - y) % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  if (x > y) {
    long long z = (x - y) / 2;
    x -= 3 * z;
    y -= z;
  } else {
    long long z = (y - x) / 2;
    y -= 3 * z;
    x -= z;
  }
  if (x >= 0 && x == y && x % 4 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
