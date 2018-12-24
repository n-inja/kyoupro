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
  long long t, a, b, c, d;
  cin >> t >> a >> b >> c >> d;
  if (a + c <= t)
    cout << b + d << endl;
  else if (c <= t)
    cout << d << endl;
  else if (a <= t)
    cout << b << endl;
  else
    cout << 0 << endl;
  return 0;
}
