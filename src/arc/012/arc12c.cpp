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

vector<string> mp;

int count(char c) {
  int ret = 0;
  for(int i = 0; i < 19; i++) for(int j = 0; j < 19; j++) if(mp[i][j] == c) ret++;
  return ret;
}

bool f(char c) {
  bool ret = false;
  for(int i = 0; i < 19 - 4; i++) for(int j = 0; j < 19; j++) if(c == mp[i][j] && c == mp[i + 1][j] && c == mp[i + 2][j] && c == mp[i + 3][j] && c == mp[i + 4][j]) ret = true;
  for(int i = 0; i < 19; i++) for(int j = 0; j < 19 - 4; j++) if(c == mp[i][j] && c == mp[i][j + 1] && c == mp[i][j + 2] && c == mp[i][j + 3] && c == mp[i][j + 4]) ret = true;
  for(int i = 0; i < 19 - 4; i++) for(int j = 0; j < 19 - 4; j++) {
    if(c == mp[i][j] && c == mp[i + 1][j + 1] && c == mp[i + 2][j + 2] && c == mp[i + 3][j + 3] && c == mp[i + 4][j + 4]) ret = true;
    if(c == mp[i + 4][j] && c == mp[i + 3][j + 1] && c == mp[i + 2][j + 2] && c == mp[i + 1][j + 3] && c == mp[i][j + 4]) ret = true;
  }
  return ret;
}

int main() {
  mp.resize(19);
  for(int i = 0; i < 19; i++) cin >> mp[i];
  int black = count('o');
  int white = count('x');
  if(black == white + 1) {
    for(int i = 0; i < 19; i++) for(int j = 0; j < 19; j++) if(mp[i][j] == 'o') {
      mp[i][j] = '.';
      if(!f('o') && !f('x')) {
        cout << "YES" << endl;
        return 0;
      }
      mp[i][j] = 'o';
    }
  }
  if(black == white) {
    for(int i = 0; i < 19; i++) for(int j = 0; j < 19; j++) if(mp[i][j] == 'x') {
      mp[i][j] = '.';
      if(!f('o') && !f('x')) {
        cout << "YES" << endl;
        return 0;
      }
      mp[i][j] = 'x';
    }
  }
  if(black == white && black == 0) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}