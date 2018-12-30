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

long long f(long long x, long long y) {
  return 100000000 * (x + 10000000) + (y + 10000000);
}

long long invx(long long h) { return (h / 100000000) - 10000000; }
long long invy(long long h) { return h % 100000000 - 10000000; }

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  map<long long, int> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[f(x[i] + a[j], y[i] + b[j])]++;
    }
  }
  long long ansx = 0, ansy = 0;
  long long maxNum = 0;
  for (auto &it : mp) {
    if (it.second > maxNum) {
      maxNum = it.second;
      ansx = invx(it.first);
      ansy = invy(it.first);
    }
  }
  cout << ansx << " " << ansy << endl;
  return 0;
}
