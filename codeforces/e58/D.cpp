#include <algorithm>
#include <bitset>
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
vector<int> a;
vector<vector<int>> p;
vector<int> d;
vector<int> buf;

void eqdfs(int i, int dep, int from) {
  buf.push_back(i);
  for (auto &j : p[i]) {
    if (j == from || a[i] != a[j])
      continue;
    eqdfs(j, dep + 1, i);
  }
  d[i] = dep + 1;
  return;
}

void ddfs(int i, int dep, int from, int di) {
  buf.push_back(i);
  for (auto &j : p[i]) {
    if (j == from || a[j] % di != 0)
      continue;
    ddfs(j, dep + 1, i, di);
  }
  d[i] = dep + 1;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  p.resize(n);
  d.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    p[l].push_back(r);
    p[r].push_back(l);
  }
  int ans = 0;

  vector<bool> used(n);
  for (int i = 0; i < n; i++) {
    if (used[i] || a[i] == 1)
      continue;
    buf.clear();
    eqdfs(i, 0, -1);
    int maxId = i;
    for (auto &j : buf) {
      used[j] = true;
      if (d[j] > d[maxId]) {
        maxId = j;
      }
    }
    buf.clear();
    eqdfs(maxId, 0, -1);
    for (auto &j : buf) {
      ans = max(ans, d[j]);
    }
  }

  for (int di = 2; di * di <= 200000; di++) {
    vector<bool> used2(n);
    for (int i = 0; i < n; i++) {
      if (used2[i] || a[i] % di != 0)
        continue;
      buf.clear();
      ddfs(i, 0, -1, di);
      int maxId = i;
      for (auto &j : buf) {
        used2[j] = true;
        if (d[j] > d[maxId]) {
          maxId = j;
        }
      }
      buf.clear();
      ddfs(maxId, 0, -1, di);
      for (auto &j : buf) {
        ans = max(ans, d[j]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
