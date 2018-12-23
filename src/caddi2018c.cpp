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

long long pw(long long e, long long x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return pw(e * e, x / 2);
  return e * pw(e, x - 1);
}

int main() {
  long long n, p;
  cin >> n >> p;
  if (n == 1) {
    cout << p << endl;
    return 0;
  }
  long long ans = 1;
  if (n > 1000000) {
    cout << 1 << endl;
    return 0;
  }
  for (long long i = 2; pw(i, n) <= p; i++) {
    if (p % pw(i, n) == 0)
      ans = i;
  }
  cout << ans << endl;
  return 0;
}
