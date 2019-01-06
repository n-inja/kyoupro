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
  long long query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  vector<long long> v(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 0; i < n; i++)
    cin >> v[i];
  RMQ q(1 << 18);
  vector<int> inv(n);
  q.update(0, 0);
  for (int i = 0; i < n; i++)
    inv[h[i] - 1] = i;
  for (int i = 0; i < n; i++) {
    q.update(inv[i] + 1, q.query(0, inv[i] + 1) - v[inv[i]]);
  }
  cout << -q.query(0, n + 1) << endl;
  return 0;
}
