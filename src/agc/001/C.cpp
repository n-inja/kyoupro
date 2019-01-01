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
int n, k;
vector<int> d;
vector<vector<int>> p;
vector<pair<int, int>> pv;

void dfs(int now, int dep, int from) {
  d[now] = dep;
  for (auto &i : p[now]) {
    if (from != i)
      dfs(i, dep + 1, now);
  }
}

int main() {
  cin >> n >> k;
  d.resize(n);
  p.resize(n);
  pv.resize(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
    pv[i] = make_pair(a, b);
  }
  int ans = n;
  if (k % 2 == 0) {
    for (int i = 0; i < n; i++) {
      int ret = 0;
      dfs(i, 0, -1);
      for (auto &j : d) {
        if (j > k / 2)
          ret++;
      }
      ans = min(ans, ret);
    }
  } else {
    for (auto &pr : pv) {
      int ret = 0;
      dfs(pr.first, 0, pr.second);
      dfs(pr.second, 0, pr.first);
      for (auto &j : d) {
        if (j > k / 2)
          ret++;
      }
      ans = min(ans, ret);
    }
  }
  cout << ans << endl;
  return 0;
}
