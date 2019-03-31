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
long long p = 1000000007;

long long power(long long e, long long x) {
  e %= p;
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return power((e * e) % p, x / 2);
  return (e * power(e, x - 1)) % p;
}

long long inv(long long a) { return power(a % p, p - 2); }

long long f(long long a, long long b) {
  if (b > a)
    swap(a, b);
  long long ret = 1;
  for (long long i = 1; i <= b; i++) {
    long long abi = (a + b + p - i + 1) % p;
    ret = (((ret * abi) % p) * inv(i)) % p;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long ans = 1;
  long long bef = 0;
  int befId = -1;
  bool b = false;
  for (int i = 0; i < n; i++) {
    if (b && a[i] < 0) {
      continue;
    } else if (!b && a[i] < 0) {
      b = true;
      befId = i;
      bef = a[i - 1];
    } else if (b && a[i] >= 0) {
      ans = (ans * f(a[i] - bef, i - befId)) % p;
      b = false;
    } else {
      continue;
    }
  }
  cout << ans << endl;
  return 0;
}
