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

int hx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int hy[8] = {1, -1, 0, 0, -1, 1, 1, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h), ans(h), ch(h);
  for(int i = 0; i < h; i++) {
    cin >> mp[i];
    for(int j = 0; j < w; j++) {
      ans[i].push_back('#');
      ch[i].push_back('.');
    }
  }
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
    if(mp[i][j] == '.') {
      ans[i][j] = '.';
      for(int k = 0; k < 8; k++) {
        int x = j + hx[k];
        int y = i + hy[k];
        if(x < 0 || x >= w || y < 0 || y >= h) continue;
        ans[y][x] = '.';
      }
    }
  }

  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
    if(ans[i][j] == '#') {
      ch[i][j] = '#';
      for(int k = 0; k < 8; k++) {
        int x = j + hx[k];
        int y = i + hy[k];
        if(x < 0 || x >= w || y < 0 || y >= h) continue;
        ch[y][x] = '#';
      }
    }
  }

  for(int i = 0; i < h; i++) {
    if(mp[i] != ch[i]) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout << "possible" << endl;
  for(int i = 0; i < h; i++) cout << ans[i] << endl;

  return 0;
}
