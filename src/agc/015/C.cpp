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
  int h, w, q;
  cin >> h >> w >> q;
  vector<string> mp(h);
  for (int i = 0; i < h; i++)
    cin >> mp[i];
  int lrdp[h + 1][w + 1];
  int uddp[h + 1][w + 1];
  int bdp[h + 1][w + 1];
  for (int i = 0; i <= h; i++)
    for (int j = 0; j <= w; j++)
      lrdp[i][j] = uddp[i][j] = bdp[i][j] = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      bdp[i + 1][j + 1] =
          bdp[i][j + 1] + bdp[i + 1][j] - bdp[i][j] + (mp[i][j] == '1' ? 1 : 0);
    }
  for (int i = 1; i < h; i++)
    for (int j = 0; j < w; j++) {
      uddp[i + 1][j + 1] =
          uddp[i][j + 1] + uddp[i + 1][j] - uddp[i][j] +
          (mp[i][j] == mp[i - 1][j] && mp[i][j] == '1' ? 1 : 0);
    }
  for (int i = 0; i < h; i++)
    for (int j = 1; j < w; j++) {
      lrdp[i + 1][j + 1] =
          lrdp[i][j + 1] + lrdp[i + 1][j] - lrdp[i][j] +
          (mp[i][j] == mp[i][j - 1] && mp[i][j] == '1' ? 1 : 0);
    }
  for (int i = 0; i < q; i++) {
    int x, y, x2, y2;
    cin >> y >> x >> y2 >> x2;
    int vsum =
        bdp[y2][x2] + bdp[y - 1][x - 1] - bdp[y2][x - 1] - bdp[y - 1][x2];
    int udsum = uddp[y2][x2] + uddp[y][x - 1] - uddp[y2][x - 1] - uddp[y][x2];
    int lrsum = lrdp[y2][x2] + lrdp[y - 1][x] - lrdp[y2][x] - lrdp[y - 1][x2];
    cout << vsum - udsum - lrsum << endl;
  }
  return 0;
}
