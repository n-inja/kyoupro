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
  static const long long BASE = 0;
  int n;
  RMQ(int _) {
    n = _;
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = BASE;
  }
  void update(int index, long long val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = data[i * 2 + 1] + data[i * 2 + 2];
    }
  }
  // [a, b)
  long long query(int a, int b, int k, int l, int r) {
    if (a < 0)
      return BASE;
    if (r <= a || b <= l)
      return BASE;
    if (a <= l && r <= b)
      return data[k];
    else
      return query(a, b, k * 2 + 1, l, (l + r) / 2) +
             query(a, b, k * 2 + 2, (r + l) / 2, r);
  }
  long long query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector<int> binv(n);
  for (int i = 0; i < n; i++)
    binv[b[i] - 1] = i;
  long long ans = 0;
  int size = 1 << 19;
  RMQ rmq(size);
  for (int i = n - 1; i >= 0; i--) {
    ans += min(rmq.query(0, binv[i]), rmq.query(binv[i], size));
    rmq.update(binv[i], 1);
  }
  cout << ans << endl;
  return 0;
}
