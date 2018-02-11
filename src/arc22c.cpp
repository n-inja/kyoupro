#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &dep, vector<vector<int>> &p, int i, int d) {
  if (dep[i] >= 0)
    return;
  dep[i] = d;
  for (int j = 0; j < p[i].size(); j++)
    dfs(dep, p, p[i][j], d + 1);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> p(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[b].push_back(a);
    p[a].push_back(b);
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++)
    d[i] = -1;
  dfs(d, p, 0, 0);
  int id = 0;
  for (int i = 0; i < n; i++)
    if (d[id] < d[i])
      id = i;
  for (int i = 0; i < n; i++)
    d[i] = -1;
  dfs(d, p, id, 0);
  int maxId = 0;
  for (int i = 0; i < n; i++)
    if (d[maxId] < d[i])
      maxId = i;
  cout << id + 1 << " " << maxId + 1 << endl;
  return 0;
}
