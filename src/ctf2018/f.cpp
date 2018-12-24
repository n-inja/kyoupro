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
int n, m, k;
vector<int> p, d;
vector<vector<int>> inv;
set<int> avail;

void dfs(int to, int dep) {
  d[to] = dep;
  for (auto &i : inv[to]) {
    dfs(i, dep + 1);
  }
}

void erase(int i) {
  avail.erase(i);
  for (auto &j : inv[i])
    erase(j);
}

void get(int now, int ex, vector<int> &a) {
  if (ex == now || avail.find(now) == avail.end())
    return;
  a.push_back(d[now]);
  for (auto &j : inv[now])
    get(j, ex, a);
}

int main() {
  cin >> n >> m >> k;
  p.resize(n);
  inv.resize(n);
  d.resize(n);
  int root;
  for (int i = 0; i < n; i++) {
    avail.insert(i);
    int t;
    cin >> t;
    if (t > 0) {
      t--;
      p[i] = t;
      inv[t].push_back(i);
    } else {
      root = i;
    }
  }
  dfs(root, 1);
  vector<int> ans(m);
  vector<int> w;
  for (int i = 0; i < m; i++) {
    int minId = -1;
    for (auto &j : avail) {
      w.clear();
      get(root, j, w);
      sort(w.begin(), w.end());
      if (w.size() < m - i - 1) {
        continue;
      }
      int minsum = 0, maxsum = 0;
      for (int l = 0; l < m - i - 1; l++) {
        minsum += w[l];
        maxsum += w[w.size() - 1 - l];
      }

      if (k - d[j] >= 0 && minsum <= k - d[j] && k - d[j] <= maxsum) {
        k -= d[j];
        minId = j;
        break;
      }
    }
    if (minId < 0) {
      cout << -1 << endl;
      return 0;
    }
    ans[i] = minId;
    erase(minId);
  }

  cout << ans[0] + 1;
  for (int i = 1; i < m; i++)
    cout << " " << ans[i] + 1;
  cout << endl;

  return 0;
}
