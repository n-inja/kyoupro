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
  map<int, multiset<int>> mp;
  vector<vector<int>> s(n);
  for (int i = 0; i < n; i++) {
    s[i].resize(n);
    for (int j = 0; j < n; j++) {
      cin >> s[i][j];
    }
  }
  int hx[4] = {0, 0, 1, -1};
  int hy[4] = {1, -1, 0, 0};
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp.find(s[i][j]) == mp.end()) {
        for (int k = 0; k < 4; k++) {
          mp[s[i][j]].insert(s[(i + hx[k] + n) % n][(j + hy[k] + n) % n]);
        }
      } else {
        multiset<int> test;
        for (int k = 0; k < 4; k++) {
          test.insert(s[(i + hx[k] + n) % n][(j + hy[k] + n) % n]);
        }
        if (mp[s[i][j]] != test && ok) {
          cout << s[i][j] << endl;
          ok = false;
        }
      }
    }
  }
  cout << ok << endl;
  return 0;
}
