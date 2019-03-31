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

#define P 1000000007

using namespace std;

int main() {
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  vector<int> xx, yy;
  int id = 0;
  for(; s[id] == 'F'; id++);
  x -= id;
  bool dir = true;
  int c = 0;
  for(int i = id; i < s.size(); i++) {
    if(dir) {
      if(s[i] == 'T') {
        dir = false;
        xx.push_back(c);
        c = 0;
      } else c++;
    } else {
      if(s[i] == 'T') {
        dir = true;
        yy.push_back(c);
        c = 0;
      } else c++;
    }
  }
  if(dir) xx.push_back(c);
  else yy.push_back(c);
  if(x < 0) x = -x;
  if(y < 0) y = -y;
  int sx = 0, sy = 0;
  for(int i = 0; i < xx.size(); i++) sx += xx[i];
  for(int i = 0; i < yy.size(); i++) sy += yy[i];
  if(x == sx && y == sy) {
    cout << "Yes" << endl;
    return 0;
  }
  if(x > sx || y > sy || (sx - x) % 2 == 1 || (sy - y) % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  sx = (sx - x) / 2;
  sy = (sy - y) / 2;
  bool dpx[xx.size() + 1][sx + 1] = {0};
  dpx[0][0] = true;
  for(int i = 0; i < xx.size(); i++) for(int j = 0; j < sx + 1; j++) {
    dpx[i + 1][j] = dpx[i][j];
    if(j - xx[i] >= 0) dpx[i + 1][j] = dpx[i][j - xx[i]];
  }
  if(!dpx[xx.size()][sx]) {
    cout << "No" << endl;
    return 0;
  }
  bool dpy[yy.size() + 1][sy + 1] = {0};
  dpy[0][0] = true;
  for(int i = 0; i < yy.size(); i++) for(int j = 0; j < sy + 1; j++) {
    dpy[i + 1][j] = dpy[i][j];
    if(j - yy[i] >= 0) dpy[i + 1][j] = dpy[i][j - yy[i]];
  }
  if(!dpy[yy.size()][sy]) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
