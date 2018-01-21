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
#include<queue>
 
using namespace std;

int hx[4] = {0, 0, 1, -1}, hy[4] = {1, -1, 0, 0};

struct Node {
  int x, y, d, k;
};

bool operator<(const Node &lhs, const Node &rhs) {
  if(lhs.d == rhs.d) return lhs.k < rhs.k;
  return lhs.d < rhs.d;
}

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> mp(R);
  for(int i = 0; i < R; i++) cin >> mp[i];
  int sx, sy, cx, cy, gx, gy;
  for(int i = 0; i < R; i++) for(int j = 0; j < C; j++)
    if(mp[i][j] == 'S') {
      sx = j;
      sy = i;
    } else if(mp[i][j] == 'C') {
      cx = j;
      cy = i;
    } else if(mp[i][j] == 'G') {
      gx = j;
      gy = i;
    }
  int dpC[R][C][K + 1], dpS[R][C][K + 1], dpG[R][C][K + 1];
  bool chC[R][C][K + 1], chS[R][C][K + 1], chG[R][C][K + 1];
  for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) for(int k = 0; k < K + 1; k++) dpC[i][j][k] = dpS[i][j][k] = dpG[i][j][k] = 1000000;
  for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) for(int k = 0; k < K + 1; k++) chC[i][j][k] = chS[i][j][k] = chG[i][j][k] = false;
  multiset<Node> q;
  Node start{sx, sy, 0, 0};
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(now.k > K) continue;
    if(chS[now.y][now.x][now.k]) continue;
    chS[now.y][now.x][now.k] = true;
    if(dpS[now.y][now.x][now.k] <= now.d) continue;
    for(int k = now.k; k < K + 1; k++) if(dpS[now.y][now.x][k] > now.d) dpS[now.y][now.x][k] = now.d;
    for(int i = 0; i < 4; i++) {
      int nx = now.x + hx[i], ny = now.y + hy[i];
      if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
      if(mp[ny][nx] == 'T') continue;
      Node next{nx, ny, now.d + 1, now.k + (mp[ny][nx] == 'E')};
      q.insert(next);
    }
  }
  start.x = cx; start.y = cy;
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(now.k > K) continue;
    if(chC[now.y][now.x][now.k]) continue;
    chC[now.y][now.x][now.k] = true;
    if(dpC[now.y][now.x][now.k] <= now.d) continue;
    for(int k = now.k; k < K + 1; k++) if(dpC[now.y][now.x][k] > now.d) dpC[now.y][now.x][k] = now.d;
    for(int i = 0; i < 4; i++) {
      int nx = now.x + hx[i], ny = now.y + hy[i];
      if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
      if(mp[ny][nx] == 'T') continue;
      Node next{nx, ny, now.d + 1, now.k + (mp[ny][nx] == 'E')};
      q.insert(next);
    }
  }
  start.x = gx; start.y = gy;
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(now.k > K) continue;
    if(chG[now.y][now.x][now.k]) continue;
    chG[now.y][now.x][now.k] = true;
    if(dpG[now.y][now.x][now.k] <= now.d) continue;
    for(int k = now.k; k < K + 1; k++) if(dpG[now.y][now.x][k] > now.d) dpG[now.y][now.x][k] = now.d;
    for(int i = 0; i < 4; i++) {
      int nx = now.x + hx[i], ny = now.y + hy[i];
      if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
      if(mp[ny][nx] == 'T') continue;
      Node next{nx, ny, now.d + 1, now.k + (mp[ny][nx] == 'E')};
      q.insert(next);
    }
  }
  int ans = 1000000;
  for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) for(int k1 = 0; k1 < K + 2; k1++) for(int k2 = 0; k2 < K + 2; k2++) {
    if(mp[i][j] == 'E') {
      if(k1 == 0 || k2 == 0) continue;
      int k3 = K - (k1 - 1) - (k2 - 1);
      if(k3 < 0 || k3 > K) continue;
      ans = min(ans, dpS[i][j][k1] + 2 * dpC[i][j][k2] + dpG[i][j][k3]);
    } else {
      int k3 = K - k1 - k2;
      if(k3 < 0 || k3 > K) continue;
      ans = min(ans, dpS[i][j][k1] + 2 * dpC[i][j][k2] + dpG[i][j][k3]);
    }
  }
  if(ans < 1000000) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  
  return 0;
}