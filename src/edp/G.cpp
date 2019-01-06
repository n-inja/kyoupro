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
vector<int> memo;

int get(int i) {
  if (memo[i])
    return memo[i];
  int ret = 0;
  for (auto &j : p[i]) {
    ret = max(ret, get(j));
  }
  return memo[i] = ret + 1;
}

int main() {
  cin >> n >> m;
  p.resize(n);
  memo.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, get(i));
  }
  cout << ans - 1 << endl;
  return 0;
}
