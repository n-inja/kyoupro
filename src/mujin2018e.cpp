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
  int x, y;
  long long t;
};

bool operator<(const N &lhs, const N &rhs) { return lhs.t < rhs.t; }

string s;
int back[4][100001];
string t = "DURL";

int nex(int t, int i) { return back[i][t] - t; }

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cin >> s;
  vector<string> mp(n);
  for (int i = 0; i < n; i++)
    cin >> mp[i];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 100000; j++)
      back[i][j] = -1;
  for (int i = 0; i < 4; i++) {
    int index = -1;
    for (int j = k - 1; j >= 0; j--)
      if (s[j] == t[i])
        index = j;
    if (index < 0)
      continue;
    index += k;
    for (int j = k - 1; j >= 0; j--) {
      if (s[j] == t[i])
        index = j;
      back[i][j] = index;
    }
  }
  multiset<N> q;
  int sx = 0, sy = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mp[i][j] == 'S') {
        sx = j;
        sy = i;
      }
  q.insert({sx, sy, 0});
  bool c[1001][1001] = {0};
  int hx[4] = {0, 0, 1, -1};
  int hy[4] = {1, -1, 0, 0};
  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (c[now.y][now.x])
      continue;
    c[now.y][now.x] = true;
    if (mp[now.y][now.x] == 'G') {
      cout << now.t << endl;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int nx = now.x + hx[i];
      int ny = now.y + hy[i];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        continue;
      if (c[ny][nx] || mp[ny][nx] == '#')
        continue;
      if (nex(now.t % k, i) < 0)
        continue;
      q.insert({nx, ny, now.t + nex(now.t % k, i) + 1});
    }
  }
  cout << "-1" << endl;
  return 0;
}
