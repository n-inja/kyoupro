#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

long long P = 1000000007;
int n, m, x, y, z;

long long power(long long e, long long x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return power((e * e) % P, x / 2);
  return (power(e, x - 1) * e) % P;
}

bool ok[1 << 17][11] = {0};

bool same(vector<int> &l, vector<int> &r) {
  if (r.size() == 0)
    return false;
  int li = l.size() - 1;
  int ri = r.size() - 1;
  for (; li >= 0; li--) {
    while (l[li] > 0 && ri >= 0)
      l[li] -= r[ri--];
  }
  for (int i = 0; i < l.size(); i++)
    if (l[i] != 0)
      return false;
  return true;
}

long long memo[41][1 << 17] = {0};

int maxK(int i) {
  int ret = 0;
  while (i > 0) {
    ret++;
    i >>= 1;
  }
  return ret;
}

long long dfs(int now, int bef) {
  if (memo[now][bef] >= 0)
    return memo[now][bef];
  if (now == n) {
    if (!ok[bef][0])
      return 1;
    else
      return 0;
  }
  long long ret = 0;
  for (int k = 1; k <= 10; k++) {
    if (ok[bef][k])
      continue;
    ret = (ret + dfs(now + 1, ((bef << k) | (1 << (k - 1))) & (m - 1))) % P;
  }
  return memo[now][bef] = ret;
}

int main() {
  cin >> n >> x >> y >> z;
  m = 1 << (x + y + z - 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < m; j++)
      memo[i][j] = -1;
  for (int i = 0; i < m; i++) {
    vector<int> v;
    int k = i;
    int base = 1;
    while (k > 0) {
      if (k & 1) {
        v.push_back(base);
        base = 0;
      }
      base++;
      k >>= 1;
    }
    reverse(v.begin(), v.end());
    for (int k = 0; k <= 10; k++) {
      if (z - k < 0)
        continue;
      vector<int> w;
      w.push_back(x);
      w.push_back(y);
      if (z - k != 0)
        w.push_back(z - k);
      ok[i][k] = same(w, v);
    }
  }

  long long ans = (power(10, n) - dfs(0, 0) + P) % P;
  cout << ans << endl;
  return 0;
}
