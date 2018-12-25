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
  int a, b;
  cin >> a >> b;
  cout << max(a - 1, 0) + ((b >= a) ? 1 : 0) << endl;
  return 0;
}
