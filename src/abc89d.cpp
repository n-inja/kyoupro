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

int h, w, d;
pair<int, int> invP(int a) { return make_pair(a / h, a % h); }
int toP(int x, int y) { return x * h + y; }
int cost(int x, int y, int x2, int y2) { return abs(x - x2) + abs(y - y2); }
int cost(pair<int, int> p, pair<int, int> p2) {
  return cost(p.first, p.second, p2.first, p2.second);
}
vector<vector<int>> a;
int q;
vector<pair<int, int>> lrs;
vector<int> inv;
vector<vector<int>> path;

int solve(int l, int p) {
  int ret = 0;
  for (int i = 0; p > 0; p /= 2, i++) {
    if (p % 2 == 1) {
      ret += path[l][i];
      l += (1 << i) * d;
    }
  }
  return ret;
}

int main() {
  cin >> h >> w >> d;
  a.resize(h);
  for (int i = 0; i < h; i++) {
    a[i].resize(w);
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  }
  cin >> q;
  lrs.resize(q);
  for (int i = 0; i < q; i++)
    cin >> lrs[i].first >> lrs[i].second;
  path.resize(h * w);
  inv.resize(h * w);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      inv[a[i][j] - 1] = toP(j, i);
  for (int i = 0; i < h * w - d; i++) {
    path[i].push_back(cost(invP(inv[i]), invP(inv[i + d])));
  }
  for (int l = 1; (1 << l) * d < h * w; l++) {
    for (int i = 0; i < h * w - (1 << l) * d; i++)
      path[i].push_back(path[i][l - 1] + path[i + (1 << (l - 1)) * d][l - 1]);
  }
  for (int i = 0; i < q; i++) {
    cout << solve(lrs[i].first - 1, (lrs[i].second - lrs[i].first) / d) << endl;
  }
  return 0;
}
