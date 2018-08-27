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
  long long a[301][301] = {0};
  bool b[301][301] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  long long ans = 0;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] > a[i][k] + a[k][j]) {
          cout << -1 << endl;
          return 0;
        }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        if (i == k || j == k)
          continue;
        if (a[i][j] == a[i][k] + a[k][j])
          b[i][j] = true;
      }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (!b[i][j])
        ans += a[i][j];
  cout << ans << endl;
  return 0;
}
