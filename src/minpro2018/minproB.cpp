#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

long long powe(long long e, int x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return powe(e * e, x / 2);
  return e * powe(e, x - 1);
}

int main() {
  long long x;
  int k;
  cin >> x >> k;
  long long ans;
  ans = (x / powe(10, k) + 1) * powe(10, k);
  cout << ans << endl;
  return 0;
}
