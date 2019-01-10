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
  int n;
  cin >> n;
  if (n % 4 == 1 || n % 4 == 2) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
