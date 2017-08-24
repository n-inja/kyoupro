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
#include<utility>

const long long PRIME = 1000000007;

using namespace std;

class Node {
public:
  int x, y;
  long long d;
  Node(int _, int __, long long ___) {
    x = _;
    y = __;
    d = ___;
  }
  bool operator>(Node &rhs) const {
    return this->d > rhs.d;
  }
  bool operator<(const Node &rhs) const {
    return this->d < rhs.d;
  }
};

class Solver {
public:
  int h, w, sx, sy;
  long long t;
  vector<string> mp;
  Solver() {
    cin >> h >> w >> t;
    mp.resize(h);
    for(int i = 0; i < h; i++) cin >> mp[i];
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == 'S') {
      mp[i][j] = '.';
      sx = j; sy = i;
    }
  }
  bool solve(long long x) {
    vector<vector<bool>> b(h);
    for(int i = 0; i < h; i++) b[i].resize(w);
    multiset<Node> q;
    q.insert(Node(sx, sy, 0));
    while(q.size() > 0) {
      Node m = *q.begin();
      q.erase(q.begin());
      if(b[m.y][m.x]) continue;
      b[m.y][m.x] = true;
      if(m.d > t) return false;
      if(mp[m.y][m.x] == 'G') {
        return true;
      }
      int hx[4] = {1, -1, 0, 0};
      int hy[4] = {0, 0, 1, -1};
      for(int i = 0; i < 4; i++) {
        if(m.x + hx[i] < 0) continue;
        if(m.x + hx[i] >= w) continue;
        if(m.y + hy[i] < 0) continue;
        if(m.y + hy[i] >= h) continue;
        q.insert(Node(m.x + hx[i], m.y + hy[i], m.d + ((mp[m.y + hy[i]][m.x + hx[i]] == '#') ? x : 1)));
      }
    }
    return false;
  }
};

int main() {
  Solver s;
  long long maxt = 1000000000;
  long long mint = 1;
  while(maxt - mint > 1) {
    long long piv = (maxt + mint) / 2;
    if(s.solve(piv)) mint = piv;
    else maxt = piv;
  }
  cout << mint << endl;
  return 0;
}
