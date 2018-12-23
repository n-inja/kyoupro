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

int main() {
  long long n, k;
  cin >> n >> k;
  long long ans = 10000000000;
  for (long long a = 1; a <= n; a++) {
    if (n % a != 0)
      continue;
    long long b = n / a;
    if (b >= k)
      continue;

    long long x = a * k + b;
    ans = min(ans, x);
  }
  cout << ans << endl;
  return 0;
}
