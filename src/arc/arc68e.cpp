#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class BIT {
public:
  int n;
  vector<int> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  void add(int a, int w) {
    a += 1;
    if (a == 0 || a > n)
      return;
    for (int x = a; x <= n; x += x & -x)
      bit[x] += w;
  }
  int sum(int a) {
    a += 1;
    if (a == 0)
      return 0;
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ps(n);
  for (int i = 0; i < n; i++)
    cin >> ps[i].first >> ps[i].second;
  map<int, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; i++)
    mp[ps[i].second - ps[i].first + 1].push_back(ps[i]);
  BIT bit(1 << 20);
  int sum = n;
  for (int i = 1; i <= m; i++) {
    if (mp.find(i - 1) != mp.end()) {
      for (int j = 0; j < mp[i - 1].size(); j++) {
        bit.add(mp[i - 1][j].first, 1);
        bit.add(mp[i - 1][j].second + 1, -1);
        sum--;
      }
    }
    int ans = sum;
    for (int j = 0; j <= m; j += i) {
      ans += bit.sum(j);
    }
    cout << ans << endl;
  }
  return 0;
}
