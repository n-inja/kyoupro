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

int n;
long long k;
vector<long long> a, b;

bool f(long long m) {
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(b.begin(), b.end(), m / a[i]);
    if (it == b.end()) {
      ret += n;
    } else {
      ret += it - b.begin();
    }
  }
  return ret >= k;
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
  long long mmax = 0, mmin = 1000000000000000000ll;
  while (mmin - mmax > 1) {
    long long m = (mmax + mmin) / 2;
    if (f(m))
      mmin = m;
    else
      mmax = m;
  }
  cout << mmin << endl;
  return 0;
}
