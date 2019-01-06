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
int n;
vector<long long> wmemo, bmemo;
vector<vector<int>> p;
long long P = 1000000007;

long long dfs(int i, bool b, int from) {
  if (b && bmemo[i] >= 0)
    return bmemo[i];
  if (!b && wmemo[i] >= 0)
    return wmemo[i];
  if (b) {
    long long ret = 1;
    for (auto &j : p[i]) {
      if (from == j)
        continue;
      ret *= dfs(j, false, i);
      ret %= P;
    }
    return bmemo[i] = ret;
  } else {
    long long ret = 1;
    for (auto &j : p[i]) {
      if (from == j)
        continue;
      ret *= (dfs(j, true, i) + dfs(j, false, i)) % P;
      ret %= P;
    }
    return wmemo[i] = ret;
  }
}

int main() {
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    p[x].push_back(y);
    p[y].push_back(x);
  }
  wmemo.resize(n);
  bmemo.resize(n);
  for (int i = 0; i < n; i++)
    wmemo[i] = bmemo[i] = -1;
  cout << (dfs(0, 0, -1) + dfs(0, 1, -1)) % P << endl;
  return 0;
}
