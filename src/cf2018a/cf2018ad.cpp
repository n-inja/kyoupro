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

long long P = 1000000007;

class BIT {
public:
  int n;
  vector<long long> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  // add v[a] + w
  void add(int a, long long w) {
    w = (w + P) % P;
    a++;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] = (bit[x] + w) % P;
  }
  // [0, a)
  long long sum(int a) {
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret = (ret + bit[x]) % P;
    return ret;
  }
};

long long t, f, d;
int n;
vector<long long> x;
long long pw2[100100];

int main() {
  BIT bit(1 << 20);
  cin >> d >> f >> t >> n;
  x.resize(n + 3);
  x[n + 1] = d;
  x[n + 2] = d * 2;
  for (int i = 0; i < n; i++)
    cin >> x[i + 1];
  pw2[0] = 1;
  for (int i = 1; i <= n + 10; i++)
    pw2[i] = (pw2[i - 1] * 2) % P;
  bit.add(0, 1);
  bit.add(1, -1);
  for (int i = 0; i <= n + 1; i++) {
    auto bt = upper_bound(x.begin(), x.end(), x[i] + f - t);
    auto et = upper_bound(x.begin(), x.end(), x[i] + f);
    int bid = bt - x.begin(), eid = et - x.begin();
    long long dp = bit.sum(i + 1);
    bit.add(bid, (pw2[bid - i - 1] * dp) % P);
    bit.add(eid, -(pw2[bid - i - 1] * dp) % P);
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long dp = bit.sum(i + 1);
    if (x[i] + f - t >= d)
      ans = (ans + (pw2[n - i] * dp) % P) % P;
  }
  ans = (ans + bit.sum(n + 2)) % P;
  cout << ans << endl;
  return 0;
}
