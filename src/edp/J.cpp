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
  double pdp[n + 1][n + 1][n + 1], edp[n + 1][n + 1][n + 1];
  int b[3] = {0};
  for (int i = 0; i < n; i++)
    b[a[i] - 1]++;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        pdp[i][j][k] = edp[i][j][k] = 0.;
  pdp[b[0]][b[1]][b[2]] = 1.0;
  edp[b[0]][b[1]][b[2]] = 0.0;

  double eps = 0.000000001;
  for (int s = n; s >= 0; s--) {
    for (int i = 0; i <= s; i++) {
      for (int j = 0; j <= s - i; j++) {
        int k = s - i - j;
        if (i == b[0] && j == b[1] && k == b[2]) {
          continue;
        }
        double psum = 0.;
        if (i < n)
          psum += pdp[i + 1][j][k] * (i + 1) / n;
        if (j < n && i > 0)
          psum += pdp[i - 1][j + 1][k] * (j + 1) / n;
        if (k < n && j > 0)
          psum += pdp[i][j - 1][k + 1] * (k + 1) / n;
        if (psum < eps) {
          continue;
        }
        pdp[i][j][k] = psum;
        edp[i][j][k] = 1.0;
        if (i < n)
          edp[i][j][k] += edp[i + 1][j][k] * (i + 1) / n;
        if (j < n && i > 0)
          edp[i][j][k] += edp[i - 1][j + 1][k] * (j + 1) / n;
        if (k < n && j > 0)
          edp[i][j][k] += edp[i][j - 1][k + 1] * (k + 1) / n;

        cout << i << " " << j << " " << k << " " << pdp[i][j][k] << " "
             << edp[i][j][k] << endl;
      }
    }
  }
  cout << edp[0][0][0] << endl;
  return 0;
}
