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
long long n;
vector<long long> v, w, s;

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
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

bool f(long long x) {
  for (int i = 0; i < n; i++) {
    w[i] = (v[i] - x) >= 0 ? 1 : -1;
  }
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + w[i];
  }
  using pll = pair<long long, long long>;
  vector<pll> p(n + 1);
  for (int i = 0; i < n + 1; i++) {
    p[i].first = i;
    p[i].second = s[i];
  }
  sort(p.begin(), p.end(), [](const pll &l, const pll &r) {
    if (l.second == r.second)
      return l.first < r.first;
    return l.second < r.second;
  });
  BIT bit(1 << 18);
  long long cnt = 0;
  for (int i = 0; i < n + 1; i++) {
    bit.add(p[i].first, 1);
    cnt += bit.sum(p[i].first);
  }
  return cnt * 2 >= n * (n + 1) / 2;
}

int main() {
  cin >> n;
  v.resize(n);
  w.resize(n);
  s.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long mn = 0, mx = 1000000001;
  while (mx - mn > 1) {
    long long mm = (mn + mx) / 2;
    if (f(mm)) {
      mn = mm;
    } else {
      mx = mm;
    }
  }
  cout << mn << endl;
  return 0;
}
