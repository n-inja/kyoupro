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

struct N {
  int x, y, cost;
};

bool operator<(const N &lhs, const N &rhs) { return lhs.cost < rhs.cost; }

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (int i = 0; i < h; i++)
    cin >> mp[i];
  multiset<N> q;
  int x, y;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (mp[i][j] == 's') {
        x = j;
        y = i;
      }
  N start{x, y, 0};
  q.insert(start);

  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (now.y < 0 || now.y >= h || now.x < 0 || now.x >= w)
      continue;
    if (mp[now.y][now.x] == '*' || mp[now.y][now.x] == '#')
      continue;
    if (mp[now.y][now.x] == 'g') {
      cout << "Yes" << endl;
      return 0;
    }
    mp[now.y][now.x] = '*';
    for (int i = 0; i < 4; i++) {
      N next{now.x + hx[i], now.y + hy[i], now.cost + 1};
      q.insert(next);
    }
  }
  cout << "No" << endl;
  return 0;
}
