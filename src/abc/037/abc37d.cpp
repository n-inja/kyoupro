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
  int x, y;
  long long a;
} Pos;

bool operator>(const Pos &lhs, const Pos &rhs) {
  return lhs.a > rhs.a;
}

bool operator<(const Pos &lhs, const Pos &rhs) {
  return lhs.a < rhs.a;
}

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<long long>> dp(h);
  vector<vector<long long>> a(h);
  for(int i = 0; i < h; i++) dp[i].resize(w);
  for(int i = 0; i < h; i++) a[i].resize(w);
  vector<Pos> p;
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
    cin >> a[i][j];
    p.push_back(Pos{j, i, a[i][j]});
  }
  sort(p.begin(), p.end());
  long long ans = 0;
  for(int i = 0; i < h * w; i++) {
    dp[p[i].y][p[i].x] = 1;
    for(int j = 0; j < 4; j++) {
      int x = p[i].x + hx[j];
      int y = p[i].y + hy[j];
      if(x < 0 || x >= w || y < 0 || y >= h) continue;
      if(a[y][x] == p[i].a) continue;
      dp[p[i].y][p[i].x] = (dp[p[i].y][p[i].x] + dp[y][x]) % 1000000007;
    }
    ans = (ans + dp[p[i].y][p[i].x]) % 1000000007;
  }

  cout << ans << endl;
  return 0;
}
