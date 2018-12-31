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
  long long l;
  int n;
  cin >> l >> n;
  vector<long long> x(n + 2), y(n + 2);
  x[n + 1] = l;
  y[0] = l;
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  for (int i = 1; i <= n; i++)
    y[i] = l - x[i];
  if (n == 1) {
    cout << max(x[1], y[1]) << endl;
    return 0;
  }
  if (n == 2) {
    cout << max(max(x[2], y[1]), max(x[1] * 2 + y[2], x[1] + y[2] * 2)) << endl;
    return 0;
  }
  long long ans = max(x[n], y[1]);
  long long ls = x[1], rs = y[2] * 2;
  ans = max(ans, ls + rs);
  ans = max(ans, ls + rs + x[1] - (x[n + 1] - x[2]) + (x[n + 1] - x[3]) * 2);
  for (int i = 2; i <= n / 2; i++) {
    ls += x[i] - x[i - 1];
    ls += x[i - 1] * 2;
    rs -= (x[i + i - 1] - x[i]) * 2;
    rs += (x[n + 1] - x[i + i]) * 2;
    ans = max(ans, ls + rs);
    ans = max(ans, ls + rs + x[i] - (x[n + 1] - x[i + 1]) +
                       (x[n + 1] - x[i + i + 1]) * 2);
  }
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  ls = y[1], rs = x[2] * 2;
  ans = max(ans, ls + rs);
  ans = max(ans, ls + rs + y[1] - (y[n + 1] - y[2]) + (y[n + 1] - y[3]) * 2);
  for (int i = 2; i <= n / 2; i++) {
    ls += y[i] - y[i - 1];
    ls += y[i - 1] * 2;
    rs -= (y[i + i - 1] - y[i]) * 2;
    rs += (y[n + 1] - y[i + i]) * 2;
    ans = max(ans, ls + rs);
    ans = max(ans, ls + rs + y[i] - (y[n + 1] - y[i + 1]) +
                       (y[n + 1] - y[i + i + 1]) * 2);
  }

  cout << ans << endl;
  return 0;
}
