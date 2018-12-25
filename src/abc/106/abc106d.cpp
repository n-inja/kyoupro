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

int d[501][501] = {0};
int memo[501][501];

int dfs(int l, int r) {
  if (l > r)
    return 0;
  if (memo[l][r] >= 0)
    return memo[l][r];
  if (l == r)
    return memo[l][r] = d[l][l];
  if (r - l > 1) {
    return memo[l][r] =
               d[l][r] + dfs(l + 1, r) + dfs(l, r - 1) - dfs(l + 1, r - 1);
  } else {
    return memo[l][r] = d[l][r] + dfs(l, l) + dfs(r, r);
  }
}

int main() {
  for (int i = 0; i < 501; i++)
    for (int j = 0; j < 501; j++)
      memo[i][j] = -1;
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> lr(m);
  for (int i = 0; i < m; i++) {
    cin >> lr[i].first >> lr[i].second;
  }
  vector<pair<int, int>> que(q);
  for (int i = 0; i < q; i++) {
    cin >> que[i].first >> que[i].second;
  }
  for (int i = 0; i < m; i++)
    d[lr[i].first][lr[i].second]++;
  for (int i = 0; i < q; i++) {
    cout << dfs(que[i].first, que[i].second) << endl;
  }

  return 0;
}
