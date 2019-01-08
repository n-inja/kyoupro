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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  double edp[n + 1][n + 1][n + 1];
  int b[3] = {0};
  for (int i = 0; i < n; i++)
    b[a[i] - 1]++;
  edp[0][0][0] = 0.0;

  for (int k = 0; k <= n; k++) {
    for (int j = 0; j <= n; j++) {
      for (int i = 0; i <= n; i++) {
        if (i == 0 && j == 0 && k == 0) {
          continue;
        }
        if (i + j + k > n)
          continue;
        edp[i][j][k] = 1.0;
        if (i > 0)
          edp[i][j][k] += edp[i - 1][j][k] * i / n;
        if (j > 0 && i < n)
          edp[i][j][k] += edp[i + 1][j - 1][k] * j / n;
        if (k > 0 && j < n)
          edp[i][j][k] += edp[i][j + 1][k - 1] * k / n;
        edp[i][j][k] /= (double)(i + j + k) / n;
      }
    }
  }
  printf("%.12lf\n", edp[b[0]][b[1]][b[2]]);
  return 0;
}
