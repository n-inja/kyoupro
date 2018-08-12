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

long long f(long long x, long long b) {
  long long ret = 0;
  if (b <= 1)
    return -1;
  while (x > 0) {
    ret += x % b;
    x /= b;
  }
  return ret;
}

/*
p + q = s;
p *b + q = x
*/
int main() {
  long long n, s;
  cin >> n >> s;
  if (n == s) {
    cout << n + 1 << endl;
    return 0;
  }
  if (s > n) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 2; i * i <= n; i++) {
    if (s == f(n, i)) {
      cout << i << endl;
      return 0;
    }
  }
  long long ans = 100000000000;
  for (long long i = 1; i * i <= n && i <= s; i++) {
    long long j = s - i;
    if ((n - j) / i) {
      if (f(n, ((n - j) / i)) == s)
        ans = min(ans, (n - j) / i);
    }
  }
  if (ans >= 100000000000)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}
