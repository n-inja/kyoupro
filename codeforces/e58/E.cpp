#include <algorithm>
#include <bitset>
#include <cstdlib>
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
  scanf("%d", &n);
  long long w = 0, h = 0;
  for (int i = 0; i < n; i++) {
    char c;
    long long x, y;
    scanf("\n%c %lld %lld", &c, &x, &y);
    long long b = max(x, y), s = min(x, y);
    if (c == '+') {
      w = max(w, b);
      h = max(h, s);
    } else {
      if (w <= b && h <= s) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
