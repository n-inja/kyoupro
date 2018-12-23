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
  for (int i = 0; i < n; i++)
    cin >> a[i];
  // rdp[i][j] = [i, n)
  long long rdp[n + 1][16];
  // ldp[i][j] = [0, i)
  long long ldp[n + 1][16];
  long long pw4[40] = {0};
  pw4[0] = 1;
  for (int i = 0; i < 39; i++)
    pw4[i + 1] = pw4[i] * 4;
  for (int i = 0; i < 16; i++) {
    rdp[n][i] = 0;
    rdp[n - 1][i] = i * 2;
  }
  for (int i = n - 2; i >= 0; i--) {
    int k = 0;
    for (int j = 0; j < 16; j++) {
      while (a[i] * pw4[j] > a[i + 1] * pw4[k] && k < 16)
        k++;
      if (k < 16) {
        rdp[i][j] = j * 2 + rdp[i + 1][k];
      } else {
        rdp[i][j] = rdp[i][j - 1] + (n - i) * 2;
      }
    }
  }
  for (int i = 0; i < 16; i++) {
    ldp[0][i] = 0;
    ldp[1][i] = i * 2 + 1;
  }
  for (int i = 1; i < n; i++) {
    int k = 0;
    for (int j = 0; j < 16; j++) {
      while (a[i - 1] * pw4[k] < a[i] * pw4[j] && k < 16)
        k++;
      if (k < 16) {
        ldp[i + 1][j] = j * 2 + ldp[i][k] + 1;
      } else {
        ldp[i + 1][j] = ldp[i + 1][j - 1] + (i + 1) * 2;
      }
    }
  }
  long long ans = rdp[0][0];
  for (int i = 0; i < n; i++) {
    ans = min(ans, ldp[i + 1][0] + rdp[i + 1][0]);
  }
  cout << ans << endl;
  return 0;
}
