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

map<long long, bool> mp;
long long n;
long long p = 998244353;

void s(int y, int x, bool b) { mp[y * n + x] = b; }

int get(int y, int x) {
  if (mp.find(y * n + x) == mp.end())
    return -1;
  return mp[y * n + x];
}

struct N {
  int y, x, b;
};

long long pw(long long e, long long x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e % p;
  if (x % 2 == 0)
    return pw((e * e) % p, x / 2);
  return (e * pw(e, x - 1)) % p;
}

int main() {
  int m;
  cin >> n >> m;
  vector<N> ns(m);

  for (int i = 0; i < m; i++) {
    cin >> ns[i].y >> ns[i].x >> ns[i].b;
    ns[i].x--;
    ns[i].y--;
    s(ns[i].y, ns[i].x, ns[i].b);
  }
  long long ms = (n - 3) * (n - 2) / 2;
  if (ms < 0)
    ms = 0;
  for (int i = 0; i < m; i++) {
    if (abs(ns[i].y - ns[i].x) >= 3) {
      if (get(ns[i].x, ns[i].y) == -1) {
        // 1
        ms--;
      } else {
        if (get(ns[i].x, ns[i].y) != ns[i].b) {
          cout << 0 << endl;
          return 0;
        }
        if (ns[i].x > ns[i].y)
          ms--;
      }
    }
  }

  long long dp[n][1 << 5];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (1 << 5); j++)
      dp[i][j] = 0;
  if (get(0, 0) == -1) {
    dp[0][0] = dp[0][1 << 2] = 1;
  } else if (get(0, 0)) {
    dp[0][1 << 2] = 1;
  } else {
    dp[0][0] = 1;
  }

  for (int i = 0; i < (1 << 5); i++) {
    if (((i >> 0) & 1) || ((i >> 4) & 1))
      continue;
    int x1 = (i >> 1) & 1;
    int x2 = (i >> 2) & 1;
    int x3 = (i >> 3) & 1;
    if (get(1, 0) == 1 - x1 || get(1, 1) == 1 - x2 || get(0, 1) == 1 - x3) {
      continue;
    }
    int y = (x1 + x2 + x3) % 2;
    dp[1][i] += dp[0][y << 2];
  }
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < (1 << 5); j++) {
      int x1 = (j >> 0) & 1;
      int x2 = (j >> 1) & 1;
      int x3 = (j >> 2) & 1;
      int x4 = (j >> 3) & 1;
      int x5 = (j >> 4) & 1;
      if (get(i, i - 2) == 1 - x1 || get(i, i - 1) == 1 - x2 ||
          get(i, i) == 1 - x3 || get(i - 1, i) == 1 - x4 ||
          get(i - 2, i) == 1 - x5)
        continue;
      int y = (x1 + x5) % 2;
      if ((y + x3) % 2 != (x2 + x4) % 2)
        continue;
      for (int k = 0; k < (1 << 5); k++) {
        if (y != ((k >> 2) & 1)) {
          continue;
        }
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= p;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << 5); i++) {
    ans += dp[n - 1][i];
    ans %= p;
  }
  ans *= pw(2, ms);
  ans %= p;
  cout << ans << endl;
  return 0;
}
