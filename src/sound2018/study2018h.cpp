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

vector<long long> a, b;
long long n, k;

//[0, x]
long long sum(long long x) {
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ret += n;
    } else {
      long long y = (x + a[i] - 1) / a[i];
      auto it = lower_bound(b.begin(), b.end(), y);
      ret += it - b.begin();
    }
  }
  return ret;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long in = 0, ax = 1000000000000000001ll;
  while (ax - in > 1) {
    long long mm = (ax + in) / 2;
    if (sum(mm) < k) {
      in = mm;
    } else {
      ax = mm;
    }
  }
  cout << in << endl;
  return 0;
}
