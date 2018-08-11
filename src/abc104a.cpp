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
  if (n < 1200) {
    cout << "ABC" << endl;
  } else if (n < 2800) {
    cout << "ARC" << endl;
  } else {
    cout << "AGC" << endl;
  }
  return 0;
}
