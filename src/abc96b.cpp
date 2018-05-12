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
  int k;

  cin >> a >> b >> c;
  cin >> k;
  long long ans = a + b + c;
  long long d = max(a, max(b, c));
  ans -= d;
  for (int i = 0; i < k; i++) {
    d *= 2;
  }
  ans += d;
  cout << ans << endl;
  return 0;
}
