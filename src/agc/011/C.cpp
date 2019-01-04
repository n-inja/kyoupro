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
long long n, m;
vector<vector<int>> p;
vector<bool> used;
vector<int> bw;

bool dfs(int now, int b) {
  if (used[now])
    return bw[now] == b;
  used[now] = true;
  bw[now] = b;
  bool ret = true;
  for (auto &i : p[now]) {
    if (!dfs(i, 1 - b))
      ret = false;
  }
  return ret;
}

int main() {
  cin >> n >> m;
  p.resize(n);
  used.resize(n);
  bw.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  long long s = 0, bws = 0, other = 0;
  for (int i = 0; i < n; i++)
    if (p[i].size() == 0) {
      s++;
      used[i] = true;
    }
  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;
    if (dfs(i, 0)) {
      bws++;
    } else {
      other++;
    }
  }
  cout << n * n - (n - s) * (n - s) + other * other + (other + bws) * bws * 2
       << endl;
  return 0;
}
