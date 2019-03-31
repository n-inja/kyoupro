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

inline long long mod(long long a, long long m) { return (a % m + m) % m; }

long long extGcd(long long a, long long b, long long &p, long long &q) {
  if (b == 0) {
    p = 1;
    q = 0;
    return a;
  }
  long long d = extGcd(b, a % b, q, p);
  q -= a / b * p;
  return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<long long, long long> ChineseRem(const vector<long long> &b,
                                      const vector<long long> &m) {
  long long r = 0, M = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    long long p, q;
    long long d = extGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
    if ((b[i] - r) % d != 0)
      return make_pair(0, -1);
    long long tmp = (b[i] - r) / d * p % (m[i] / d);
    r += M * tmp;
    M *= m[i] / d;
  }
  return make_pair(mod(r, M), M);
}

int ksum(long long n, int k) {
  int ret = 0;
  while (n > 0) {
    ret += n % k;
    n /= k;
  }
  return ret;
}

vector<int> kv(long long n) {
  vector<int> b(31);
  for (int i = 2; i <= 30; i++) {
    b[i] = ksum(n, i);
  }
  return b;
}

bool same(vector<int> l, vector<int> r) {
  bool ok = true;
  for (int i = 0; i < l.size(); i++) {
    if (l[i] != r[i])
      ok = false;
  }
  return ok;
}

int main() {
  vector<int> a(31);
  vector<long long> r, m;
  for (int i = 2; i <= 30; i++) {
    cin >> a[i];
    if (i > 2) {
      r.push_back(a[i] % (i - 1));
      m.push_back(i - 1);
    }
  }
  auto pr = ChineseRem(r, m);
  long long ans = pr.first;
  if (ans <= 1000000000000LL && pr.second >= 0 && same(a, kv(ans))) {
    cout << ans << endl;
  } else {
    cout << "invalid" << endl;
  }
  return 0;
}
