#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <random>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

mt19937 mt(10000000);
int hx[4] = {0, 1, 0, -1};
int hy[4] = {-1, 0, 1, 0};
string gimmick = ".LR";
int gimmickInv[256] = {0};

struct Map {
  char old, oldX, oldY;
  int scr;
  vector<string> mp;
  vector<vector<set<int>>> track;
  vector<pair<int, int>> v;
  vector<string> s;
  vector<vector<int>> a;
  int n;
  Map(vector<string> &_s) {
    for (int i = 0; i < gimmick.size(); i++) {
      gimmickInv[gimmick[i]] = i;
    }
    s = _s;
    n = 29;
    mp.resize(29);
    track.resize(29);
    for (int i = 0; i < 29; i++) {
      track[i].resize(29);
      for (int j = 0; j < 29; j++) {
        if (i == 0 || i == 28 || j == 0 || j == 28) {
          mp[i].push_back('#');
        } else {
          mp[i].push_back('.');
        }
      }
    }
  }
  int score() {
    a.resize(n);
    v.resize(s.size());
    for (int i = 0; i < n; i++) {
      a[i].resize(n);
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      go(i);
    }
    scr = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 1)
          scr += 10;
        else if (a[i][j] == 2)
          scr += 3;
        else if (a[i][j] == 3)
          scr += 1;
      }
    }
    return scr;
  }
  void go(int i) {
    int x = n / 2, y = n / 2, d = 0;
    track[y][x].insert(i);
    for (int j = 0; j < s[i].size(); j++) {
      int rate = 1;
      if (mp[y][x] == 'D')
        rate = 2;
      if (mp[y][x] == 'T')
        rate = 3;

      if (s[i][j] == 'S') {
        for (int k = 0; k < rate; k++) {
          int nx = x + hx[d], ny = y + hy[d];
          if (mp[ny][nx] == '#')
            break;
          x = nx;
          y = ny;
          track[ny][nx].insert(i);
        }
      } else if (s[i][j] == 'L') {
        d += 4 - rate;
        d %= 4;
      } else {
        d += rate;
        d %= 4;
      }
    }
    a[y][x]++;
    v[i] = make_pair(y, x);
  }
  void cancel(int i) {
    int x = n / 2, y = n / 2, d = 0;
    track[y][x].erase(i);
    for (int j = 0; j < s[i].size(); j++) {
      int rate = 1;
      if (mp[y][x] == 'D')
        rate = 2;
      if (mp[y][x] == 'T')
        rate = 3;

      if (s[i][j] == 'S') {
        for (int k = 0; k < rate; k++) {
          int nx = x + hx[d], ny = y + hy[d];
          if (mp[ny][nx] == '#')
            break;
          x = nx;
          y = ny;
          track[ny][nx].erase(i);
        }
      } else if (s[i][j] == 'L') {
        d += 4 - rate;
        d %= 4;
      } else {
        d += rate;
        d %= 4;
      }
    }
    a[y][x]--;
  }
  int swp() {
    oldX = mt() % 27 + 1, oldY = mt() % 27 + 1;
    set<int> t = track[oldY][oldX];
    for (auto &id : t) {
      cancel(id);
    }
    old = mp[oldY][oldX];
    mp[oldY][oldX] = gimmick[(gimmickInv[old] + mt() % (gimmick.size() - 1)) %
                             gimmick.size()];
    for (auto &id : t) {
      go(id);
    }
    scr = 0;
    for (int i = 0; i < 29; i++) {
      for (int j = 0; j < 29; j++) {
        if (a[i][j] == 1)
          scr += 10;
        else if (a[i][j] == 2)
          scr += 3;
        else if (a[i][j] == 3)
          scr += 1;
      }
    }
    return scr;
  }
  void back() {
    set<int> t = track[oldY][oldX];
    for (auto &id : t) {
      cancel(id);
    }
    mp[oldY][oldX] = old;
    for (auto &id : t) {
      go(id);
    }
    scr = 0;
    for (int i = 0; i < 29; i++) {
      for (int j = 0; j < 29; j++) {
        if (a[i][j] == 1)
          scr += 10;
        else if (a[i][j] == 2)
          scr += 3;
        else if (a[i][j] == 3)
          scr += 1;
      }
    }
  }
};

int score(vector<string> &mp, vector<string> &s, vector<vector<int>> &a) {
  int n = mp.size();
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    for (int j = 0; j < n; j++)
      a[i][j] = 0;
  }
  for (int i = 0; i < s.size(); i++) {
    int x = n / 2, y = n / 2, d = 0;
    for (int j = 0; j < s[i].size(); j++) {
      int rate = 1;
      if (mp[y][x] == 'D')
        rate = 2;
      if (mp[y][x] == 'T')
        rate = 3;

      if (s[i][j] == 'S') {
        for (int k = 0; k < rate; k++) {
          int nx = x + hx[d], ny = y + hy[d];
          if (mp[ny][nx] == '#')
            break;
          x = nx;
          y = ny;
        }
      } else {
        if (mp[y][x] == 'R') {
          d += 1;
          d %= 4;
        } else if (mp[y][x] == 'L') {
          d += 3;
          d %= 4;
        } else if (s[i][j] == 'L') {
          d += 4 - rate;
          d %= 4;
        } else {
          d += rate;
          d %= 4;
        }
      }
    }
    a[y][x]++;
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1)
        ret += 10;
      else if (a[i][j] == 2)
        ret += 3;
      else if (a[i][j] == 3)
        ret += 1;
    }
  }
  return ret;
}

void outputwin(vector<string> &s) {
  for (int i = 0; i < s.size(); i++) {
    cout << s[i] << "\r\n";
  }
  cout << endl;
}

void f() {
  vector<string> mp(29);
  for (int i = 0; i < 29; i++) {
    for (int j = 0; j < 29; j++) {
      if (i == 0 || i == 28 || j == 0 || j == 28) {
        mp[i].push_back('#');
      } else if (i % 5 == 3) {
        mp[i].push_back('.');
      } else {
        mp[i].push_back('.');
      }
    }
  }
  outputwin(mp);
  return;
  int turn = 300;
  int h, w;
  h = w = 29;
  double p[301][29][29][4];
  for (int i = 0; i <= turn; i++)
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        for (int d = 0; d < 4; d++) {
          p[i][y][x][d] = 0.0;
        }
  p[0][14][14][0] = 1.0;
  for (int i = 0; i < turn; i++) {
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (mp[y][x] == '#')
          continue;
        for (int d = 0; d < 4; d++) {
          int r = 1;
          if (mp[y][x] == 'D')
            r = 2;
          if (mp[y][x] == 'T')
            r = 3;
          if (mp[y][x] == 'R') {
            p[i + 1][y][x][(d + 1) % 4] += p[i][y][x][d] * 0.5;
          } else if (mp[y][x] == 'L') {
            p[i + 1][y][x][(d + 3) % 4] += p[i][y][x][d] * 0.5;
          } else if (r == 2) {
            p[i + 1][y][x][(d + 2) % 4] += p[i][y][x][d] * 0.5;
          } else {
            p[i + 1][y][x][(d + 1) % 4] += p[i][y][x][d] * 0.25;
            p[i + 1][y][x][(d + 3) % 4] += p[i][y][x][d] * 0.25;
          }
          int nx = x, ny = y;
          for (int j = 0; j < r; j++) {
            if (mp[ny + hy[d]][nx + hx[d]] != '#') {
              ny += hy[d];
              nx += hx[d];
            } else {
              break;
            }
          }
          p[i + 1][ny][nx][d] += p[i][y][x][d] * 0.5;
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      double pr = 0.0;
      for (int k = 0; k < 4; k++) {
        pr += p[turn][i][j][k];
      }
      cout << pr << " ";
    }
    cout << endl;
  }
}

int n, m, l;

int main() {
  for (int i = 0; i < gimmick.size(); i++) {
    gimmickInv[gimmick[i]] = i;
  }
  cin >> n >> m >> l;
  vector<string> s(n), t(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = 0; i < n; i++) {
    int d = 0;
    for (int j = 0; j <= s[i].size(); j++) {
      if (j == s.size() || s[i][j] == 'S') {
        if (d) {
          if (d == 1)
            t[i].push_back('R');
          else if (d == 3)
            t[i].push_back('L');
          else if (d == 2) {
            t[i].push_back('R');
            t[i].push_back('R');
          } else {
            cerr << d << endl;
          }
        }
        d = 0;
        if (j < s.size()) {
          t[i].push_back('S');
        }
      } else {
        if (s[i][j] == 'R') {
          d += 1;
        } else {
          d += 3;
        }
        d %= 4;
      }
    }
  }
  vector<string> mp(m), best;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || i == m - 1 || j == 0 || j == m - 1)
        mp[i].push_back('#');
      else
        mp[i].push_back('L');
    }
  }
  best = mp;
  vector<vector<int>> a;
  int nowscore = score(mp, s, a);
  int bestscore = nowscore;

  for (int k = 0; k < 1000; k++) {
    int x = mt() % 27 + 1, y = mt() % 27 + 1;
    char old = mp[y][x];
    mp[y][x] =
        gimmick[(gimmickInv[old] + (mt() % (gimmick.size()))) % gimmick.size()];
    int nextscore = score(mp, s, a);
    if (nextscore > nowscore) {
      nowscore = nextscore;
      if (bestscore < nowscore) {
        bestscore = nowscore;
        best = mp;
      }
    } else {
      if (mt() % 100 > 0) {
        mp[y][x] = old;
      } else {
        nowscore = nextscore;
      }
    }
  }

  outputwin(best);
  cerr << score(best, s, a) << endl;
  return 0;
}
