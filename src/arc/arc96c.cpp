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
  long long a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (a + b > c * 2) {
    long long ans = min(x, y) * 2 * c;
    if (x > y) {
      if (a > c * 2) {
        ans += c * 2 * (x - y);
      } else {
        ans += a * (x - y);
      }
    } else {
      if (b > c * 2) {
        ans += c * 2 * (y - x);
      } else {

        ans += b * (y - x);
      }
    }
    cout << ans << endl;
  } else {
    cout << x * a + y * b << endl;
  }
  return 0;
}
