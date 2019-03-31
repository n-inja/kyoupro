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
  int x, y, t;
};

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.t < rhs.t;
}

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};
vector<string> mp;
vector<vector<double>> bri;
int sx, sy, gx, gy;
int n, m;

double p(double e, int x) {
  if(x == 0) return 1;
  if(x == 1) return e;
  if(x % 2 == 0) return p(e * e, x / 2);
  return e * p(e, x - 1);
}

bool f(double t) {
  multiset<Node> q;
  Node start{sx, sy, 0};
  vector<vector<bool>> ch(n);
  for(int i = 0; i < n; i++) {
    ch[i].resize(m);
  }
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(ch[now.y][now.x]) continue;
    ch[now.y][now.x] = true;
    if(now.x == gx && now.y == gy) {
      return true;
    }
    for(int i = 0; i < 4; i++) {
      int nx = now.x + hx[i], ny = now.y + hy[i];
      if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if(bri[ny][nx] * p(0.99, now.t + 1) < t) continue;
      Node next{nx, ny, now.t + 1};
      q.insert(next);
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  mp.resize(n);
  for(int i = 0; i < n; i++) cin >> mp[i];
  bri.resize(n);
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
    if(mp[i][j] == 's') {
      sx = j;
      sy = i;
      bri[i].push_back(1000);
    } else if(mp[i][j] == 'g') {
      gx = j;
      gy = i;
      bri[i].push_back(1000);
    } else if(mp[i][j] == '#') {
      bri[i].push_back(-1);
    } else {
      bri[i].push_back(mp[i][j] - '0');
    }
  }
  
  if(!f(0)) {
    cout << -1 << endl;
    return 0;
  }
  
  double maxT = 10, minT = 0;
  while(maxT - minT > 0.0000000001) {
    double m = (maxT + minT) / 2;
    if(f(m)) minT = m;
    else maxT = m;
  }
  printf("%.9lf\n", minT);
  return 0;
}
