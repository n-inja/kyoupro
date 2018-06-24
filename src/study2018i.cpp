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

long long n, m;
vector<long long> x, z;

bool f(long long y) {
  long long now = 0;
  bool ret = false;
  if (x[0] - 1 < y) {
    now = max(x[0], y - x[0]);
    for (int i = 1; i < m; i++) {
      if (now < x[i])
        break;
      now = x[i] + y;
    }
    ret = true;
  }
  return ret;
}

bool g(long long y) {
  long long now = 0;
  bool ret = false;
  if (z[0] - 1 < y) {
    now = max(z[0], y - z[0]);
    for (int i = 1; i < m; i++) {
      if (now < z[i])
        break;
      now = z[i] + y;
    }
    ret = true;
  }
  return ret;
}

int main() {
  cin >> n >> m;
  x.resize(m);
  for (int i = 0; i < m; i++)
    cin >> x[i];
  z = x;
  reverse(z.begin(), z.end());
  for (int i = 0; i < m; i++)
    z[i] = n - z[i] + 1;
  long long in = 0, ax = 1000000001;
  while (ax - in > 1) {
    long long mm = (in + ax) / 2;
    if (f(mm) || g(mm)) {
      ax = mm;
    } else {
      in = mm;
    }
  }
  cout << ax << endl;
  return 0;
}
