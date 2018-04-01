#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int h = 100, w = 100;

  string white = "", black = "";
  for (int i = 0; i < w; i++) {
    white.push_back('.');
    black.push_back('#');
  }
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    if (i < h / 2)
      s[i] = white;
    else
      s[i] = black;
  }
  a--;
  b--;
  int cntw = 0, cnth = 0;
  // black
  for (int i = 0; i < b; i++) {
    s[cnth * 2][cntw * 2] = '#';
    cntw++;
    if (cntw >= w / 2) {
      cnth++;
      cntw = 0;
    }
  }
  // white
  cntw = 0;
  cnth = 49;
  for (int i = 0; i < a; i++) {
    s[cnth * 2 + 1][cntw * 2] = '.';
    cntw++;
    if (cntw >= w / 2) {
      cnth--;
      cntw = 0;
    }
  }
  cout << w << " " << h << endl;
  for (int i = 0; i < h; i++)
    cout << s[i] << endl;
  return 0;
}
