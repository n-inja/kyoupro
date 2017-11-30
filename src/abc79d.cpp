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

int main() {
  int h, w;
  cin >> h >> w;
  int p[10][10];
  int a[h][w];
  for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cin >> p[i][j];
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
  for(int k = 0; k < 10; k++) for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
  int ans = 0;
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(a[i][j] >= 0) ans += p[a[i][j]][1];
  cout << ans << endl;
  return 0;
}
