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
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  long long d = min(c, b);
  ans += d * 2;
  c -= d;
  b -= d;
  if (c > 0) {
    ans += min(c, a + 1);
  } else {
    ans += b;
  }
  cout << ans << endl;
  return 0;
}
