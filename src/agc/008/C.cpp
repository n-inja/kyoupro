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
  vector<int> a(7);
  for (int i = 0; i < 7; i++)
    cin >> a[i];
  long long ans = 0;
  ans += a[0] / 2 * 2;
  ans += a[1];
  ans += a[3] / 2 * 2;
  ans += a[4] / 2 * 2;
  if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
    long long ret = 3;
    a[0]--;
    a[3]--;
    a[4]--;
    ret += a[0] / 2 * 2;
    ret += a[1];
    ret += a[3] / 2 * 2;
    ret += a[4] / 2 * 2;
    ans = max(ans, ret);
  }
  cout << ans << endl;
  return 0;
}
