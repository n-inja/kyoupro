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
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }
  int sum(int a) {
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  int size = 1 << 19;
  int n;
  cin >> n;
  BIT bit(size);
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      cin >> q;
      bit.add(q, 1);
    } else {
      cin >> q;
      int ansMax = 0, ansMin = 200001;
      while (ansMin - ansMax > 1) {
        int m = (ansMax + ansMin) / 2;
        if (bit.sum(m) >= q) {
          ansMin = m;
        } else {
          ansMax = m;
        }
      }
      cout << ansMin << endl;
      bit.add(ansMin, -1);
    }
  }
  return 0;
}
