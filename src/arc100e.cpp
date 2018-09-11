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

struct Z {
  long long st, nd;
  void f(Z a) {
    long long v[4] = {st, nd, a.st, a.nd};
    sort(v, v + 4);
    st = v[3];
    nd = v[2];
  }
};

void zeta(int n, vector<Z> &v) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (1 << n); j++)
      if (j & (1 << i))
        v[j].f(v[j ^ (1 << i)]);
}

int main() {
  int n, m;
  cin >> n;
  m = (1 << n);
  vector<long long> v(m);
  for (int i = 0; i < m; i++)
    cin >> v[i];
  vector<Z> z(m);
  for (int i = 0; i < m; i++) {
    z[i].st = v[i];
    z[i].nd = 0;
  }
  zeta(n, z);
  long long bef = z[0].st + z[0].nd;
  for (int i = 1; i < m; i++) {
    bef = max(bef, z[i].st + z[i].nd);
    cout << bef << endl;
  }
  return 0;
}
