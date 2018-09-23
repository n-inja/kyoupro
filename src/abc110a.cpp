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
  int a, b, c;
  cin >> a >> b >> c;
  int d = max(a, b) * 10 + min(a, b) + c;
  int e = max(b, c) * 10 + min(b, c) + a;
  int f = max(c, a) * 10 + min(c, a) + b;
  cout << max(d, max(e, f)) << endl;
  return 0;
}
