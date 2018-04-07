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
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long ans = 0, sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  bool c = true;
  for (int i = 0; i < n; i++)
    if (a[i] != b[i])
      c = false;
  if (c) {
    cout << 0 << endl;
    return 0;
  }
  long long d = 1000000001;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i])
      d = min(d, b[i]);
  }
  cout << sum - d << endl;
  return 0;
}
