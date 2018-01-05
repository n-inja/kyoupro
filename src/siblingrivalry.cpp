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
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  vector<pair<int, int>> uv(m);
  for(int i = 0; i < m; i++) cin >> uv[i].first >> uv[i].second;
  vector<vector<int>> p(n);
  for(int i = 0; i < m; i++) p[uv[i].second - 1].push_back(uv[i].first - 1);
  vector<vector<vector<bool>>> bd(n);
  for(int i = 0; i < n; i++) bd[i].resize(102);
  for(int i = 0; i < n; i++) for(int j = 0; j < 102; j++) bd[i][j].resize(n);
  for(int i = 0; i < n; i++) bd[i][0][i] = true;
  for(int l = 0; l < n; l++) for(int i = 0; i < 101; i++) for(int j = 0; j < n; j++) if(bd[l][i][j]) for(int k = 0; k < p[j].size(); k++) bd[l][i + 1][p[j][k]] = true;
  vector<int> ans(n);
  for(int i = 0; i < n; i++) ans[i] = -1;
  ans[n - 1] = 0;

  for(int i = 1; i <= n; i++) {
    bool bb = false;
    vector<int> bit(n);
    for(int j = 0; j < n; j++) if(ans[j] >= 0) for(int k = 0; k < n; k++) {
      if(bd[j][a][k]) bit[k] |= 1;
      if(bd[j][b][k]) bit[k] |= 2;
      if(bd[j][c][k]) bit[k] |= 4;
    }
    for(int j = 0; j < n; j++) if(bit[j] == 7 && ans[j] < 0) {
      if(j == 0) {
        cout << i << endl;
        return 0;
      }
      ans[j] = i;
      bb = true;
    }
    if(!bb) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  cout << ans[0] << endl;
  return 0;
}
