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

int dp[2002][2002] = {0};
long long h, w;

long long ma(long long a, long long b) { return a > b ? a : b; }

long long mi(long long a, long long b) { return a > b ? b : a; }

int mem(int x1, int y1, int x2, int y2) {
  x1 = ma(0, x1);
  y1 = ma(0, y1);
  x2 = mi(w - 1, x2);
  y2 = mi(h - 1, y2);
  return dp[y2 + 1][x2 + 1] - dp[y1][x2 + 1] - dp[y2 + 1][x1] + dp[y1][x1];
}

int main() {
  cin >> h >> w;
  long long n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  vector<bool> r(n), c(m);
  vector<vector<string>> st(4);
  for (int i = 0; i < 4; i++) {
    st[i].resize(n);
    for (int j = 0; j < n; j++)
      st[i][j] = s[j];
  }
  unsigned long long ans = h * w;
  int sx[4] = {0, (int)ma(-m + 1, m - w), 0, (int)ma(-m + 1, m - w)};
  int sy[4] = {0, 0, (int)ma(-n + 1, n - h), (int)ma(-n + 1, n - h)};
  int sw = mi(m - 1, w - m);
  int sh = mi(n - 1, h - n);
  for (int i = 1; i <= n * 2; i++)
    for (int j = 1; j <= m * 2; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      if (i <= h && j <= w && s[i - 1][j - 1] == '#')
        dp[i][j]++;
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      st[0][i][j] = (mem(j - sw, i - sh, j, i) == 0) ? '.' : '#';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      st[1][i][j] = (mem(j, i - sh, j + sw, i) == 0) ? '.' : '#';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      st[2][i][j] = (mem(j - sw, i, j, i + sh) == 0) ? '.' : '#';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      st[3][i][j] = (mem(j, i, j + sw, i + sh) == 0) ? '.' : '#';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (st[0][i][j] == '.')
        ans--;
    }
  for (int i = 0; i < n; i++)
    for (int j = ma(0, 2 * m - w); j < m; j++) {
      if (st[1][i][j] == '.')
        ans--;
    }
  for (int i = ma(0, 2 * n - h); i < n; i++)
    for (int j = 0; j < m; j++) {
      if (st[2][i][j] == '.')
        ans--;
    }
  for (int i = ma(0, 2 * n - h); i < n; i++)
    for (int j = ma(0, 2 * m - w); j < m; j++) {
      if (st[3][i][j] == '.')
        ans--;
    }
  unsigned long long hsize = h - n * 2;
  unsigned long long wsize = w - m * 2;
  if (2 * n < h) {
    for (int i = 0; i < m; i++)
      if (st[0][n - 1][i] == '.')
        ans -= hsize;
    for (int i = ma(0, 2 * m - w); i < m; i++)
      if (st[1][n - 1][i] == '.')
        ans -= hsize;
  }
  if (2 * m < w) {
    for (int i = 0; i < n; i++)
      if (st[0][i][m - 1] == '.')
        ans -= wsize;
    for (int i = ma(0, 2 * n - h); i < n; i++)
      if (st[2][i][m - 1] == '.')
        ans -= wsize;
  }
  if (dp[n][m] == 0)
    cout << 0 << endl;
  else
    cout << ans << endl;
  return 0;
}
