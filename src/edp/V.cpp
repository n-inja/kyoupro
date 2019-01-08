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
long long m;
vector<vector<int>> p;
vector<vector<long long>> bmemo, amemo;
vector<map<int, long long>> cmemo;
vector<int> parent;

long long dfs(int i, int from) {
  parent[i] = from;
  vector<long long> v;
  for (auto &j : p[i]) {
    if (j == from)
      v.push_back(1);
    else
      v.push_back((dfs(j, i) + 1) % m);
  }
  long long ret = 1;
  bmemo[i].push_back(ret);
  for (int j = 0; j < p[i].size(); j++) {
    ret *= v[j];
    ret %= m;
    bmemo[i].push_back(ret);
  }
  long long back = 1;
  amemo[i].push_back(back);
  for (int j = (int)p[i].size() - 1; j >= 0; j--) {
    back *= v[j];
    back %= m;
    amemo[i].push_back(back);
  }
  reverse(amemo[i].begin(), amemo[i].end());
  return ret;
}

long long dfs2(int i, int from) {
  if (cmemo[i].find(from) != cmemo[i].end())
    return cmemo[i][from];
  auto it = lower_bound(p[i].begin(), p[i].end(), from);
  cmemo[i][from] = 1;
  if (parent[i] >= 0)
    cmemo[i][from] *= (dfs2(parent[i], i) + 1) % m;
  cmemo[i][from] *= bmemo[i][it - p[i].begin()];
  cmemo[i][from] %= m;
  cmemo[i][from] *= amemo[i][it - p[i].begin() + 1];
  cmemo[i][from] %= m;
  return cmemo[i][from];
}

long long dfs3(int i) {
  if (parent[i] < 0) {
    return amemo[i][0];
  }
  return (amemo[i][0] * (dfs2(parent[i], i) + 1)) % m;
}

int main() {
  cin >> n >> m;
  bmemo.resize(n);
  amemo.resize(n);
  cmemo.resize(n);
  parent.resize(n);
  p.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, s;
    cin >> a >> s;
    a--;
    s--;
    p[a].push_back(s);
    p[s].push_back(a);
  }
  for (int i = 0; i < n; i++)
    sort(p[i].begin(), p[i].end());
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    cout << dfs3(i) << endl;
  }
  return 0;
}
