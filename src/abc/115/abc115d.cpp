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

// a[0] = 1
// a[i] = a[i - 1] * 2 + 1
vector<long long> a(51), b(51);
long long ans = 0;

long long f(int n, long long x) {
  if (x <= 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }
  if (a[n] <= x) {
    return b[n];
  } else if (a[n - 1] + 2 <= x) {
    return b[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
  } else if (a[n - 1] + 1 <= x) {
    return b[n - 1];
  } else {
    return f(n - 1, x - 1);
  }
}

int main() {
  int n;
  long long x;
  cin >> n >> x;
  a[0] = 1;
  b[0] = 1;
  for (int i = 0; i < 50; i++) {
    a[i + 1] = a[i] * 2 + 3;
    b[i + 1] = b[i] * 2 + 1;
  }
  cout << f(n, x) << endl;
  return 0;
}
