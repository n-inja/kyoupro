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

class RMQ {
  vector<long long> data;

public:
  static const long long INF = 100000000000;
  int n;
  RMQ(int _) {
    n = _;
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = -1;
  }
  void update(int index, long long val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  // [a, b)
  long long query(int a, int b, int k, int l, int r) {
    if (a < 0)
      return -1;
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return data[k];
    else
      return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                 query(a, b, k * 2 + 2, (r + l) / 2, r));
  }
  long long query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  int n;
  cin >> n;
  n--;
  vector<int> c(n), a(n);
  for (int i = 0; i < n; i++)
    cin >> c[i] >> a[i];
  vector<int> grundy(n + 1);
  RMQ rmq(1 << 18);
  grundy[0] = 0;
  rmq.update(0, 0);
  for (int i = 1; i < n + 1; i++) {
    int mmax = -1, mmin = 100000;
    while (mmin - mmax > 1) {
      int m = (mmax + mmin) / 2;
      if (rmq.query(0, m + 1) < i - c[i - 1]) {
        mmin = m;
      } else {
        mmax = m;
      }
    }
    //    cout << mmax << " " << mmin << endl;
    rmq.update(mmin, i);
    grundy[i] = mmin;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] % 2 == 1)
      ans ^= grundy[i + 1];

  if (ans)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
