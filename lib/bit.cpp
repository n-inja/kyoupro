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

class BIT {
public:
  int n;
  vector<int> bit;

  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }

  // add v[a] + w
  void add(int a, int w) {
    a++;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }

  // [0, a)
  int sum(int a) {
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};
