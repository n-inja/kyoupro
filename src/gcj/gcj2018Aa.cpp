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
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    string ans;
    int r, c, h, v;
    cin >> r >> c >> v >> h;
    vector<string> mp(r);
    for (int i = 0; i < r; i++)
      cin >> mp[i];
    int cnt = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cnt += (mp[i][j] == '@') ? 1 : 0;
    if (cnt == 0) {
      cout << "Case #" << k + 1 << ": POSSIBLE" << endl;
      continue;
    }
    if (cnt % ((h + 1) * (v + 1)) == 0) {
      int ver = cnt / (v + 1);
      vector<int> chips(r);
      for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
          chips[i] += (mp[i][j] == '@') ? 1 : 0;
        }
      vector<int> vcut;
      vcut.push_back(0);
      int cu = 0;
      bool b = false;
      for (int i = 0; i < r; i++) {
        cu += chips[i];
        if (cu == ver) {
          vcut.push_back(i + 1);
          cu = 0;
        } else if (cu > ver) {
          b = true;
          break;
        } else if (cu < ver && cu > 0 && i == r - 1) {
          b = true;
        }
      }
      if (b || vcut.size() != v + 2) {
        cout << "Case #" << k + 1 << ": IMPOSSIBLE" << endl;
        continue;
      }
      vcut[v + 1] = r;
      int hol = ver / (h + 1);
      vector<vector<int>> hchips(v + 1);
      for (int i = 0; i < v + 1; i++)
        hchips[i].resize(c);
      for (int i = 0; i < v + 1; i++)
        for (int j = vcut[i]; j < vcut[i + 1]; j++)
          for (int l = 0; l < c; l++) {
            hchips[i][l] += (mp[j][l] == '@') ? 1 : 0;
          }
      vector<int> cus(v + 1), ccut;
      b = false;
      for (int i = 0; i < c; i++) {
        for (int j = 0; j < v + 1; j++)
          cus[j] += hchips[j][i];
        bool over = false, ok = true, zero = true;
        for (int j = 0; j < v + 1; j++)
          if (cus[j] > hol)
            over = true;
        for (int j = 0; j < v + 1; j++)
          if (cus[j] != hol)
            ok = false;
        for (int j = 0; j < v + 1; j++)
          if (cus[j] != 0)
            zero = false;
        if (over) {
          b = true;
          break;
        }
        if (ok) {
          ccut.push_back(i);
          for (int j = 0; j < v + 1; j++)
            cus[j] = 0;
          continue;
        }
        if (i == c - 1 && !zero) {
          b = true;
          break;
        }
      }
      if (b || ccut.size() == 0) {
        cout << "Case #" << k + 1 << ": IMPOSSIBLE" << endl;
        continue;
      }
      ans = "POSSIBLE";
    } else {
      ans = "IMPOSSIBLE";
    }
    cout << "Case #" << k + 1 << ": " << ans << endl;
  }
  return 0;
}
