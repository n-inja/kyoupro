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

vector<vector<int>> mp;
vector<string> s;

int hx[4] = {1, -1, 0, 0};
int hy[4] = {0, 0, 1, -1};

int dfs(int i, int j, int id) {
  if(mp[i][j] > 0 || s[i][j] == 'x') return 0;
  mp[i][j] = id;
  for(int k = 0; k < 4; k++) {
    if(i + hy[k] < 0 || i + hy[k] >= 10 || j + hx[k] < 0 || hx[k] >= 10) continue;
    dfs(i + hy[k], j + hx[k], id);
  }
  return id;
}

bool ch(int i, int j, int s) {
  if(mp[i][j] > 0) return false;
  set<int> ans;
  for(int k = 0; k < 4; k++) {
    if(i + hy[k] < 0 || i + hy[k] >= 10 || j + hx[k] < 0 || hx[k] >= 10) continue;
    if(mp[i + hy[k]][j + hx[k]] > 0) ans.insert(mp[i + hy[k]][j + hx[k]]);
  }
  return (ans.size() >= s);
}

int main() {
  mp.resize(10);
  s.resize(10);
  for(int i = 0; i < 10; i++) cin >> s[i];
  for(int i = 0; i < 10; i++) mp[i].resize(10);
  int id = 1;
  for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) {
    int b = dfs(i, j, id);
    if(b > 0) {
      id = b + 1;
    }
  }
  for(int i = 0; i < 10; i++ ) {
    for(int j = 0; j < 10; j++) {
      cout << mp[i][j];
    }
    cout << endl;
  }
  for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) if(ch(i, j, id - 1)) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
