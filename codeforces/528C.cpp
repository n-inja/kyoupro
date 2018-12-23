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

long long d(int x, int y, int x2, int y2) { return abs(x - x2) + abs(y - y2); }
bool in(int x, int y, int x2, int y2, int i, int j) {
  if (x <= i && i <= x2 && y <= j && j <= y2) {
    if (x == i || y2 == j)
      return true;
  }
  if (x <= i && i <= x2 && y2 <= j && j <= y) {
    if (i == x2 || j == y)
      return true;
  }
  if (x2 <= i && i <= x && y <= j && j <= y2) {
    if (x == i || y2 == j)
      return true;
  }
  if (x2 <= i && i <= x && y2 <= j && j <= y) {
    if (i == x2 || j == y)
      return true;
  }
  return false;
}

int main() {
  int w = 1001, h = 1001;
  int x[3], y[3];
  for (int i = 0; i < 3; i++)
    cin >> x[i] >> y[i];
  long long ans = h * w;
  int ax, ay;
  for (int i = 0; i < w; i++)
    for (int j = 0; j < h; j++) {
      long long m =
          d(i, j, x[0], y[0]) + d(i, j, x[1], y[1]) + d(i, j, x[2], y[2]);
      if (ans > m) {
        ans = m;
        ax = i;
        ay = j;
      }
    }
  cout << ans + 1 << endl;
  for (int i = 0; i < w; i++)
    for (int j = 0; j < h; j++) {
      for (int k = 0; k < 3; k++)
        if (in(ax, ay, x[k], y[k], i, j)) {
          cout << i << " " << j << endl;
          break;
        }
    }
  return 0;
}
