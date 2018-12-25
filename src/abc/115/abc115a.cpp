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
  int x;
  cin >> x;
  if (x == 22) {
    cout << "Christmas Eve Eve Eve" << endl;
  } else if (x == 23) {
    cout << "Christmas Eve Eve" << endl;
  } else if (x == 24) {
    cout << "Christmas Eve" << endl;
  } else {
    cout << "Christmas" << endl;
  }
  return 0;
}
