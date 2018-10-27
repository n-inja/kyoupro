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

int main() {
  int n;
  cin >> n;
  int m = n * 2;
  int id = -1;
  for (int i = 1; i * i <= m; i++) {
    if (i * (i + 1) == m) {
      id = i;
    }
  }
  if (id < 0) {
    cout << "No" << endl;
    return 0;
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  cout << "Yes" << endl;
  m = m / id;
  vector<vector<int>> ans(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; ans[i].size() < id; j++) {
      int k = *s.begin();
      s.erase(s.begin());
      ans[i].push_back(k);
      ans[i + j + 1].push_back(k);
    }
  }
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << ans[i].size();
    for (int j = 0; j < ans[i].size(); j++)
      cout << " " << ans[i][j] + 1;
    cout << endl;
  }
  return 0;
}
