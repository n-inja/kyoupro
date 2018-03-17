#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int rx, lx, uy, dy;
};

map<int, map<int, int>> mp;

bool exist(int x, int y) {
  if (mp.find(y) == mp.end())
    return false;
  if (mp[y].find(x) == mp[y].end())
    return false;
  return true;
}

vector<Node> nodes;

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int x = 0, y = 0;
  nodes.push_back(Node{1, -1, 1, -1});
  mp[0][0] = 0;
  for (int i = 0; i < k; i++) {
    int bx = x, by = y;
    while (exist(x, y)) {
      if (s[i] == 'L') {
        x = nodes[mp[y][x]].lx;
      } else if (s[i] == 'R') {
        x = nodes[mp[y][x]].rx;
      } else if (s[i] == 'U') {
        y = nodes[mp[y][x]].uy;
      } else {
        y = nodes[mp[y][x]].dy;
      }
    }
    if (s[i] == 'L') {
      int rx = bx + 1, lx = x - 1, uy = y + 1, dy = y - 1;
      while (exist(lx, y)) {
        lx = nodes[mp[y][lx]].lx;
      }
      while (exist(rx, y)) {
        rx = nodes[mp[y][rx]].rx;
      }
      while (exist(x, uy)) {
        uy = nodes[mp[uy][x]].uy;
      }
      while (exist(x, dy)) {
        dy = nodes[mp[dy][x]].dy;
      }
      nodes.push_back(Node{rx, lx, uy, dy});
    } else if (s[i] == 'R') {
      int rx = x + 1, lx = bx - 1, uy = y + 1, dy = y - 1;
      while (exist(lx, y)) {
        lx = nodes[mp[y][lx]].lx;
      }
      while (exist(rx, y)) {
        rx = nodes[mp[y][rx]].rx;
      }
      while (exist(x, uy)) {
        uy = nodes[mp[uy][x]].uy;
      }
      while (exist(x, dy)) {
        dy = nodes[mp[dy][x]].dy;
      }
      nodes.push_back(Node{rx, lx, uy, dy});
    } else if (s[i] == 'U') {
      int rx = x + 1, lx = x - 1, uy = y + 1, dy = by - 1;
      while (exist(lx, y)) {
        lx = nodes[mp[y][lx]].lx;
      }
      while (exist(rx, y)) {
        rx = nodes[mp[y][rx]].rx;
      }
      while (exist(x, uy)) {
        uy = nodes[mp[uy][x]].uy;
      }
      while (exist(x, dy)) {
        dy = nodes[mp[dy][x]].dy;
      }
      nodes.push_back(Node{rx, lx, uy, dy});
    } else {
      int rx = x + 1, lx = x - 1, uy = by + 1, dy = y - 1;
      while (exist(lx, y)) {
        lx = nodes[mp[y][lx]].lx;
      }
      while (exist(rx, y)) {
        rx = nodes[mp[y][rx]].rx;
      }
      while (exist(x, uy)) {
        uy = nodes[mp[uy][x]].uy;
      }
      while (exist(x, dy)) {
        dy = nodes[mp[dy][x]].dy;
      }
      nodes.push_back(Node{rx, lx, uy, dy});
    }
    mp[y][x] = i + 1;
  }
  cout << x << " " << y << endl;
  return 0;
}
