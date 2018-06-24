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

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> gp(n + 1);
  vector<string> mp(h);
  for (int i = 0; i < h; i++) {
    cin >> mp[i];
  }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == 'S') {
        gp[0].first = j;
        gp[0].second = i;
      } else if (mp[i][j] >= '1' && mp[i][j] <= '9') {
        gp[mp[i][j] - '0'].first = j;
        gp[mp[i][j] - '0'].second = i;
      }
    }

  int hx[4] = {0, 0, 1, -1};
  int hy[4] = {1, -1, 0, 0};

  int ans = 0;
  for (int i = 0; i < n; i++) {
    multiset<N> q;
    N start{gp[i].first, gp[i].second, 0};
    q.insert(start);
    vector<vector<bool>> ch(h);
    for (int j = 0; j < h; j++)
      ch[j].resize(w);
    while (q.size() > 0) {
      N now = *q.begin();
      q.erase(q.begin());
      if (ch[now.y][now.x])
        continue;
      ch[now.y][now.x] = true;
      if (now.y == gp[i + 1].second && now.x == gp[i + 1].first) {
        ans += now.cost;
        break;
      }
      for (int j = 0; j < 4; j++) {
        int nx = now.x + hx[j], ny = now.y + hy[j];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h)
          continue;
        if (mp[ny][nx] == 'X')
          continue;
        N next{nx, ny, now.cost + 1};
        q.insert(next);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
