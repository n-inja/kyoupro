#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
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
      data[i] = INF;
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
      return 0;
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return data[k];
    else
      return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                 query(a, b, k * 2 + 2, (r + l) / 2, r));
  }
};

struct P {
  int l, r;
  long long c;
};

bool operator<(const P &lhs, const P &rhs) { return lhs.r < rhs.r; }

int main() {
  int n, l;
  cin >> n >> l;
  vector<P> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].l >> ps[i].r >> ps[i].c;
  }
  sort(ps.begin(), ps.end());
  int size = 1 << 19;
  RMQ rmq(size);
  for (int i = 0; i < n; i++) {
    long long q = rmq.query(ps[i].l - 1, ps[i].r - 1, 0, 0, size);
    rmq.update(ps[i].r - 1,
               min(q + ps[i].c, rmq.query(ps[i].r - 1, ps[i].r, 0, 0, size)));
  }
  cout << rmq.query(l - 1, l, 0, 0, size) << endl;
  cerr << "a";
  return 0;
}
