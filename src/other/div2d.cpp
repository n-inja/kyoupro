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
  int a, b, c;
  cin >> a >> b >> c;
  for (int t = 0; t < 1000; t++) {
    if ((60 * t + c) % (a + b) <= a) {
      cout << 60 * t + c << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
