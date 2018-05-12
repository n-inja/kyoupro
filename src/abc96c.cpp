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

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (int i = 0; i < h; i++)
    cin >> mp[i];
  bool ans = true;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == '#') {
        bool c = false;
        for (int k = 0; k < 4; k++) {
          int y = i + hy[k];
          int x = j + hx[k];
          if (x < 0 || x >= w || y < 0 || y >= h)
            continue;
          if (mp[y][x] == '#')
            c = true;
        }
        if (!c)
          ans = false;
      }
    }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
