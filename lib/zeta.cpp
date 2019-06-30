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
  long long val;

  void f(Z a) { val += a.val; }
};

// v'[i] = Σ v[j] (j in i)
// v = v'
void zeta(int n, vector<Z> &v) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (1 << n); j++)
      if (j & (1 << i))
        v[j].f(v[j ^ (1 << i)]);
}
