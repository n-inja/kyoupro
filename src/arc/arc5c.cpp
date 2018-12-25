#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
 
using namespace std;

struct Node {
  int x, y, t, b;
};

bool operator<(const Node lhs, const Node rhs) {
  return lhs.t < rhs.t;
}

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  vector<vector<vector<bool>>> ch(3);
  for(int i = 0; i < 3; i++) {
    ch[i].resize(h);
    for(int j = 0; j < h; j++) {
      ch[i][j].resize(w);
    }
  }
  for(int i = 0; i < h; i++) cin >> mp[i];
  int sx, sy;
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == 's') {
    sx = j;
    sy = i;
  }
  Node start{sx, sy, 0, 0};
  multiset<Node> q;
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(ch[now.b][now.y][now.x]) continue;
    ch[now.b][now.y][now.x] = true;
    if(mp[now.y][now.x] == 'g') {
      cout << "YES" << endl;
      return 0;
    }
    for(int i = 0; i < 4; i++) {
      int nx = now.x + hx[i], ny = now.y + hy[i];
      if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      Node next{nx, ny, now.t + 1, now.b};
      if(mp[ny][nx] == '#') next.b++;
      if(next.b > 2) continue;
      q.insert(next);
    }
  }
  cout << "NO" << endl;
  return 0;
}