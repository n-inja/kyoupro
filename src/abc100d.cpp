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

int xx[8] = {1, 1, 1, 1, -1, -1, -1, -1};
int yy[8] = {1, 1, -1, -1, -1, -1, 1, 1};
int zz[8] = {1, -1, 1, -1, 1, -1, 1, -1};

struct N {
  long long x, y, z;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<N> ns(n);
  for (int i = 0; i < n; i++)
    cin >> ns[i].x >> ns[i].y >> ns[i].z;
  long long ans = -100000000000;
  for (int i = 0; i < 8; i++) {
    sort(ns.begin(), ns.end(), [&i](const N &lhs, const N &rhs) {
      return lhs.x * xx[i] + lhs.y * yy[i] + lhs.z * zz[i] >
             rhs.x * xx[i] + rhs.y * yy[i] + rhs.z * zz[i];
    });
    long long sum = 0;
    for (int j = 0; j < m; j++)
      sum += ns[j].x * xx[i] + ns[j].y * yy[i] + ns[j].z * zz[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
