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
  int caseNum;
  cin >> caseNum;
  for (int cas = 1; cas <= caseNum; cas++) {
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++)
      cin >> v[i];
    bool b = true;
    vector<int> r(t);
    for (int i = 0; i < t; i++)
      r[i] = -1;
    int c = 0;
    if (v[0] == 0 || v[t - 1] == 0)
      b = false;
    for (int i = 0; i < t; i++) {
      while (c < t && v[c] == 0)
        c++;
      if (c == t)
        break;
      r[i] = c;
      v[c]--;
    }
    while (c < t && v[c] == 0)
      c++;
    if (c < t && v[c] > 0)
      b = false;
    if (r[t - 1] < 0)
      b = false;
    if (!b) {
      cout << "Case #" << cas << ": Impossible" << endl;
      continue;
    }
    int h = 0;
    for (int i = 0; i < t; i++)
      h = max(h, abs(i - r[i]));
    h++;
    vector<string> mp(h);
    string base = "";
    for (int i = 0; i < t; i++)
      base.push_back('.');
    for (int i = 0; i < h; i++)
      mp[i] = base;
    for (int i = 0; i < t; i++) {
      if (r[i] > i) {
        for (int d = 0; d < r[i] - i; d++) {
          mp[d][i + d] = '\\';
        }
      } else if (r[i] < i) {
        for (int d = 0; d < i - r[i]; d++) {
          mp[d][i - d] = '/';
        }
      } else {
      }
    }
    cout << "Case #" << cas << ": " << h << endl;
    for (int i = 0; i < h; i++)
      cout << mp[i] << endl;
  }
  return 0;
}
