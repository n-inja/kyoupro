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
  int n;
  cin >> n;
  vector<long long> a(n);
  int dp[10][10][10] = {0};
  dp[0][0][0] = 1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (i == 0 && j == 0 && k == 0)
          continue;
        bool b = false;
        if (i > 0)
          b |= dp[i - 1][j][k];
        if (j > 0)
          b |= dp[i][j - 1][k];
        if (k > 0)
          b |= dp[i][j][k - 1];
        if (i > 0 && j > 0)
          b |= dp[i - 1][j - 1][k];
        if (j > 0 && k > 0)
          b |= dp[i][j - 1][k - 1];
        if (i > 0 && k > 0)
          b |= dp[i - 1][j][k - 1];
        dp[i][j][k] = !b;
      }
    }
  }
  for (int i = 0; i < n; i++)
    cin >> a[i];
  bool ok = true, ok2 = true;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0)
      ok = false;
    else
      ok2 = false;
  }
  if (n == 1) {
    if (a[0] % 2 == 0)
      cout << "second" << endl;
    else
      cout << "first" << endl;
    return 0;
  }
  if (n % 2 == 0) {
    if (ok2)
      cout << "second" << endl;
    else
      cout << "first" << endl;
    return 0;
  }
  if (ok || ok2) {
    cout << "second" << endl;
  } else {
    cout << "first" << endl;
  }
  return 0;
}
