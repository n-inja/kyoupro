#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
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
  void add(int a, int w) {
    a += 1;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }
  int sum(int a) {
    a += 1;
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
  // [l, r]
  int q(int l, int r) { return sum(r) - sum(l - 1); }
};
vector<int> h;
int n, k;
BIT bit(1 << 20);

bool f(int x) {
  for (int i = 0; i <= n - x; i++) {
    if (bit.q(i, i + x - 1) <= k) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> k;
  h.resize(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 0; i < n; i++)
    bit.add(i, 1 - h[i]);
  int minK = 0, maxK = n + 1;
  while (maxK - minK > 1) {
    int m = (maxK + minK) / 2;
    if (f(m)) {
      minK = m;
    } else {
      maxK = m;
    }
  }
  cout << minK << endl;
  return 0;
}
