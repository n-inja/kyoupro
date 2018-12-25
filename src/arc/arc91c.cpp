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
  long long n, m;
  cin >> n >> m;
  long long ans;
  if (n > 1 && m > 1) {
    ans = (m - 2) * (n - 2);
  }
  if (n == m && n == 1) {
    ans = 1;
  }
  if (n == 1 && m > 1) {
    ans = m - 2;
  }
  if (m == 1 && n > 1) {
    ans = n - 2;
  }
  cout << ans << endl;
  return 0;
}
