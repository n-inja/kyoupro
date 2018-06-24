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

vector<vector<int>> mp;

int hs(int x, int y) { return x * 10000 + y; }

int open = 0, w, h;
int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

bool bfs(int x, int y, int bx, int by, set<int> &used) {
  if (x == bx && y == by && used.size() == open)
    return true;
  if (used.find(hs(x, y)) != used.end())
    return false;
  bool ret = false;
  used.insert(hs(x, y));
  for (int i = 0; i < 4; i++) {
    int nx = x + hx[i], ny = y + hy[i];
    if (nx < 0 || nx > w || ny < 0 || ny >= h)
      continue;
    if (mp[ny][nx] == 1)
      continue;
    if ((nx != bx || ny != by) && used.find(hs(nx, ny)) != used.end())
      continue;
    if (bfs(nx, ny, bx, by, used)) {
      ret = true;
    }
  }

  used.erase(used.find(hs(x, y)));
  return ret;
}

int main() {
  while (true) {
    cin >> w >> h;
    if (h == 0 && w == 0)
      break;
    mp.clear();
    mp.resize(h);
    for (int i = 0; i < h; i++)
      mp[i].resize(w);
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    open = 0;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (mp[i][j] == 0)
          open++;
    set<int> s;
    int sx = -1, sy = -1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (mp[i][j] == 0) {
          sy = i;
          sx = j;
        }
    if (sx < 0) {
      cout << "Yes" << endl;
      continue;
    }
    if (bfs(sx, sy, sx, sy, s)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
