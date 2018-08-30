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

const long long P = 998244353;

using pii = pair<int, int>;

bool f(pii x, pii y, pii z) {
  int x1 = x.first - y.first;
  int y1 = x.second - y.second;
  int x2 = x.first - z.first;
  int y2 = x.second - z.second;
  return x1 * y2 - y1 * x2 == 0;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  long long pw[222] = {0};
  pw[0] = 1;
  for (int i = 0; i < n; i++)
    pw[i + 1] = (pw[i] * 2) % P;
  long long ret = pw[n];
  ret = (ret - n - 1 + P) % P;
  bool used[222][222] = {0};
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (used[i][j])
        continue;
      vector<int> v;
      v.push_back(i);
      v.push_back(j);
      for (int k = j + 1; k < n; k++) {
        if (used[i][k] || !f(p[i], p[j], p[k]))
          continue;
        v.push_back(k);
      }
      ret = (ret - pw[v.size()] + v.size() + 1 + P) % P;
      for (int k = 0; k < v.size(); k++)
        for (int h = k + 1; h < v.size(); h++)
          used[v[k]][v[h]] = true;
    }
  cout << ret << endl;
  return 0;
}
