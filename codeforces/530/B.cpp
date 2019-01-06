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
  long long n;
  cin >> n;
  long long ans = n * n * 2;
  for (long long m = 1; m * m <= n; m++) {
    long long r = (n + m - 1) / m;
    ans = min(ans, r + m);
  }
  cout << ans << endl;
  return 0;
}
