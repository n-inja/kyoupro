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
vector<long long> a;
vector<vector<int>> p;
vector<long long> q; // max, min
vector<bool> c;

long long dfs(int id, int from) {
  if (c[id])
    return q[id];
  c[id] = true;
  if (p[id].size() == 1) {
    return q[id] = a[id];
  }
  long long sum = 0;
  for (int i = 0; i < p[id].size(); i++)
    if (p[id][i] != from)
      sum += dfs(p[id][i], id);
  long long b = sum - a[id];
  long long c = a[id] - b;
  if (b < 0 || c < 0) {
    return q[id] = -1000000000000ll;
  }
  long long mm = 0;
  for (int i = 0; i < p[id].size(); i++)
    mm = max(mm, dfs(p[id][i], id));
  if (mm > sum / 2) {
    if (sum - mm < b)
      return q[id] = -1000000000000ll;
  } else {
    if (sum / 2 < b)
      return q[id] = -1000000000000ll;
  }
  return q[id] = c;
}

int main() {
  cin >> n;
  a.resize(n);
  p.resize(n);
  c.resize(n);
  q.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  if (n == 2) {
    if (a[0] == a[1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (p[i].size() == 1)
      continue;
    if (dfs(i, -1) == 0) {
      cout << "YES" << endl;
      return 0;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  return 0;
}
