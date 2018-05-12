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

vector<int> ps() {
  vector<bool> isP(55556);
  for (int i = 0; i < 55556; i++)
    isP[i] = true;
  isP[0] = isP[1] = false;
  isP[2] = true;
  for (int i = 3; i < 55556; i++) {
    if (i % 2 == 0) {
      isP[i] = false;
      continue;
    }
    for (int j = 3; j * j <= i; j++) {
      if (i % j == 0)
        isP[i] = false;
    }
  }
  vector<int> ret;
  for (int i = 0; i < 55556; i++) {
    if (isP[i] && i % 10 == 1)
      ret.push_back(i);
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> p = ps();
  cout << p[0];
  for (int i = 1; i < n; i++)
    cout << " " << p[i];
  cout << endl;
  return 0;
}
