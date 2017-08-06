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
  int h, w;
  cin >> h >> w;
  int n;
  cin >> n;
  vector<int> a;
  a.resize(n);
  vector<vector<int>> c;
  c.resize(h);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < h; i++) c[i].resize(w);
  int ww = 0, hh = 0;
  bool v = false;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < a[i]; j++) {
      if(v) {
        c[hh][ww] = i + 1;
        ww--;
        if(ww < 0) {
          ww = 0;
          hh++;
          v = false;
        }
      } else {
        c[hh][ww] = i + 1;
        ww++;
        if(ww >= w) {
          ww = w - 1;
          hh++;
          v = true;
        }
      }
    }
  }
  for(int i = 0; i < h; i++) {
    cout << c[i][0];
    for(int j = 1; j < w; j++) cout << " " << c[i][j];
    cout << endl;
  }
  return 0;
}
