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

/*
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
*/

int n, k, q;
vector<long long> a;

bool f(long long x, long long y) {
  vector<long long> c;
  int d = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= x)
      c.push_back(a[i]);
    else {
      if (c.size() < k) {
        c.clear();
        continue;
      }
      sort(c.begin(), c.end());
      auto it = upper_bound(c.begin(), c.end(), x + y);
      if (it != c.begin()) {
        it--;
        d += min((int)(it - c.begin() + 1), (int)(c.size() - k + 1));
      }
      c.clear();
    }
  }
  if (c.size() >= k) {
    sort(c.begin(), c.end());
    auto it = upper_bound(c.begin(), c.end(), x + y);
    if (it != c.begin()) {
      it--;
      d += min((int)(it - c.begin() + 1), (int)(c.size() - k + 1));
    }
  }
  //  cerr << x << " " << y << " " << d << " " << q << " " << endl;
  return d >= q;
}

int main() {
  cin >> n >> k >> q;
  a.resize(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<long long> b = a;
  sort(b.begin(), b.end());

  long long ans = 1000000001;

  for (int i = 0; i < n - q + 1; i++) {
    long long minS = 1000000001, maxS = -1;
    while (minS - maxS > 1) {
      int s = (maxS + minS) / 2;
      if (f(b[i], s)) {
        minS = s;
      } else {
        maxS = s;
      }
    }
    ans = min(ans, minS);
  }
  cout << ans << endl;
  return 0;
}
