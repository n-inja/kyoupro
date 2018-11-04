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

// sum [1, n]
long long sn(long long n) {
  if (n < 0)
    return 0;
  return n * (n + 1) / 2;
}
long long snrange(long long min_i, long long max_i) {
  return sn(max_i) - sn(min_i - 1);
}

void solve() {
  long long n, m, x, y;
  cin >> m >> n >> x >> y;
  long long ans = 0;
  long long kingng = 0, kingok = 0;
  int hx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int hy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
  bool mp[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      mp[i][j] = false;
  for (int k = 0; k < 8; k++) {
    int nx = x - 1;
    int ny = y - 1;
    for (; nx >= 0 && nx < m && ny >= 0 && ny < n;) {
      mp[ny][nx] = true;
      nx += hx[k];
      ny += hy[k];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!mp[i][j])
        kingng++;
  long long left = x - 1, right = m - x;
  kingok += left * right;
  long long down = n - y, up = y - 1;
  kingok += down * up;
  long long lu = min(x - 1, y - 1), rd = min(m - x, n - y);
  kingok += lu * rd;
  long long ld = min(x - 1, n - y), ru = min(m - x, y - 1);
  kingok += ld * ru;
  for (int i = 0; i < n; i++) {
    long long d = (n - i - 1) * m * m;
    long long e = (n - i - 1) * m;
    long long downs = max(0ll, m - 1 - (n - i - 2));
    long long f = 0;
    if (i < n - 1) {
      f = snrange(downs, m - 1) * 2;
    }
    ans += (d - e - f);
  }
  ans += kingok;
  ans -= kingng;
  cout << ans * 2 << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
