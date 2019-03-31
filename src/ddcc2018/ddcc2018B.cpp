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

bool ok(int x, int y, int n) {
  int m = n * 2;
  x *= 2;
  y *= 2;
  bool ret = true;
  for (int i = 0; i < 4; i++) {
    int xx = x;
    int yy = y;
    if (i % 2 == 0) {
      xx = m - xx;
    }
    if (i / 2 == 0) {
      yy = m - yy;
    }
    if (xx + yy < n)
      ret = false;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ok(i, j, n) && ok(i + 1, j, n) && ok(i, j + 1, n) &&
          ok(i + 1, j + 1, n))
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
