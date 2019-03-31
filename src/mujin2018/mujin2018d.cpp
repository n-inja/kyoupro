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

int rev(int i) {
  int ret = 0;
  while (i > 0) {
    ret *= 10;
    ret += i % 10;
    i /= 10;
  }
  return ret;
}

int b[1000][1000];
int c[1000][1000];

bool f(int x, int y, int i, int j) {
  int ii = i, jj = j;
  if (i == 0 || j == 0)
    return false;
  if (c[ii - 1][jj - 1] == x * 1000 + y)
    return true;
  c[ii - 1][jj - 1] = x * 1000 + y;
  if (b[i - 1][j - 1] >= 0)
    return b[i - 1][j - 1];
  if (i > j)
    j = rev(j);
  else
    i = rev(i);
  b[ii - 1][jj - 1] = f(x, y, min(i, j), max(i, j) - min(i, j));
  return b[ii - 1][jj - 1];
}

int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      b[i][j] = c[i][j] = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f(i, j, i, j))
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
