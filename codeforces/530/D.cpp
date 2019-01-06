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
vector<vector<int>> inv;
vector<int> p;
vector<long long> s, a;
long long ans = 0;
bool ok = true;

void dfs(int i, bool even) {
  if (!even) {
    ans += s[i] - s[p[i]];
    a[i] = s[i] - s[p[i]];
    if (a[i] < 0) {
      ok = false;
      return;
    }
    for (auto &j : inv[i]) {
      dfs(j, true);
    }
  } else {
    if (inv[i].size() == 0)
      return;
    long long b = 1000000000000LL;
    for (auto &j : inv[i]) {
      b = min(b, s[j] - s[p[i]]);
    }
    if (b < 0) {
      ok = false;
      return;
    }
    a[i] = b;
    ans += b;
    s[i] = s[p[i]] + a[i];
    for (auto &j : inv[i]) {
      dfs(j, false);
    }
  }
}

int main() {
  cin >> n;
  inv.resize(n);
  p.resize(n);
  s.resize(n);
  a.resize(n);

  for (int i = 1; i < n; i++)
    cin >> p[i];
  for (int i = 1; i < n; i++) {
    p[i]--;
    inv[p[i]].push_back(i);
  }
  for (int i = 0; i < n; i++)
    cin >> s[i];

  ans = a[0] = s[0];
  for (auto &i : inv[0]) {
    dfs(i, true);
  }
  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
