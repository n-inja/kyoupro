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
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  vector<vector<int>> l(n), r(n), u(n), d(n);
  for (int i = 0; i < n; i++)
    cin >> mp[i];
  for (int i = 0; i < n; i++) {
    l[i].resize(m);
    for (int j = 1; j < m; j++)
      if (mp[i][j] == '.' && mp[i][j - 1] == '.')
        l[i][j] = l[i][j - 1] + 1;
  }
  for (int i = 0; i < n; i++) {
    r[i].resize(m);
    u[i].resize(m);
    d[i].resize(m);
    for (int j = m - 2; j >= 0; j--)
      if (mp[i][j] == '.' && mp[i][j + 1] == '.')
        r[i][j] = r[i][j + 1] + 1;
  }
  for (int j = 0; j < m; j++) {
    for (int i = 1; i < n; i++)
      if (mp[i][j] == '.' && mp[i - 1][j] == '.')
        u[i][j] = u[i - 1][j] + 1;
  }
  for (int j = 0; j < m; j++) {
    for (int i = n - 2; i >= 0; i--)
      if (mp[i][j] == '.' && mp[i + 1][j] == '.')
        d[i][j] = d[i + 1][j] + 1;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '#')
        continue;
      ans += l[i][j] * d[i][j] + d[i][j] * r[i][j] + r[i][j] * u[i][j] +
             u[i][j] * l[i][j];
    }
  cout << ans << endl;
  return 0;
}
