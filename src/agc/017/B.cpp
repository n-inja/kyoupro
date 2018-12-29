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
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    long long upl = c * i + b - a;
    long long upr = d * i + b - a;
    long long dwl = c * (n - i - 1);
    long long dwr = d * (n - i - 1);
    if (!(upl > dwr || upr < dwl))
      ok = true;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
