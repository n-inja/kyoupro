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
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k % 2 == 0)
    cout << a - b << endl;
  else
    cout << b - a << endl;
  return 0;
}
