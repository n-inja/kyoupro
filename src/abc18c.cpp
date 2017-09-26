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

using namespace std;

typedef struct {
  int y, x, k;
} Node;

bool operator>(const Node &lhs, const Node &rhs) {
  return lhs.k < rhs.k;
}

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.k > rhs.k;
}

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int main() {
  int r, c, k;
  cin >> r >> c >> k;
  vector<string> mp(r);
  for(int i = 0; i < r; i++) cin >> mp[i];
  vector<vector<int>> v(r);
  for(int i = 0; i < r; i++) v[i].resize(c);
  multiset<Node> q;
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(mp[i][j] == 'x') q.insert(Node{i, j, k});
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(v[now.y][now.x] > 0) continue;
    v[now.y][now.x] = now.k;
    if(now.k == 1) continue;
    for(int i = 0; i < 4; i++) {
      if(now.x + hx[i] < 0 || now.x + hx[i] >= c || now.y + hy[i] < 0 || now.y + hy[i] >= r) continue;
      if(v[now.y + hy[i]][now.x + hx[i]] > 0) continue;
      q.insert(Node{now.y + hy[i], now.x + hx[i], now.k - 1});
    }
  }
  int ans = 0;
  for(int i = k - 1; i < r - k + 1; i++) for(int j = k - 1; j < c - k + 1; j++) if(v[i][j] == 0) ans++;
  cout << ans << endl;
  return 0;
}
