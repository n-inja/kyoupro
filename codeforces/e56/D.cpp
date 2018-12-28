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

int n, m;
vector<vector<int>> p;

vector<bool> used;
vector<int> bw;

long long P = 998244353;

pair<pair<int, int>, bool> dfs(int now, int c) {
  if (used[now])
    return make_pair(make_pair(0, 0), c == bw[now]);
  used[now] = true;
  bw[now] = c;

  pair<pair<int, int>, bool> ret;
  ret.second = true;
  ret.first.first = c == 0;
  ret.first.second = c != 0;
  for (int i = 0; i < p[now].size(); i++) {
    auto ppr = dfs(p[now][i], 1 - c);
    ret.first.first += ppr.first.first;
    ret.first.second += ppr.first.second;
    if (!ppr.second)
      ret.second = false;
  }
  return ret;
}

int main() {
  int t;
  cin >> t;
  long long p2[302020] = {0};
  p2[0] = 1;
  for (int i = 0; i < 302000; i++) {
    p2[i + 1] = (p2[i] * 2) % P;
  }
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    p.clear();
    p.resize(n);
    used.clear();
    used.resize(n);
    bw.clear();
    bw.resize(n);
    for (int j = 0; j < m; j++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      p[a].push_back(b);
      p[b].push_back(a);
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;
      auto ppr = dfs(i, 0);
      if (!ppr.second)
        ans = 0;
      else {
        if (ppr.first.first + ppr.first.second == 1) {
          ans *= 3;
          ans %= P;
        } else {
          ans *= (p2[ppr.first.first] + p2[ppr.first.second]) % P;
          ans %= P;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
