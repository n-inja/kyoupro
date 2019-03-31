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

#define P 1000000007

using namespace std;

int main() {
  int n, w, c;
  cin >> n >> w >> c;
  vector<vector<vector<int>>> dp(51);
  for(int i = 0; i < 51; i++) {
    dp[i].resize(w + 1);
    for(int j = 0; j < w + 1; j++) dp[i][j].resize(c + 1);
  }
  vector<vector<pair<int, int>>> vws(50);
  for(int i = 0; i < n; i++) {
    int color;
    pair<int, int> vw;
    cin >> vw.first >> vw.second >> color;
    vws[color - 1].push_back(vw);
  }
  int cnt = 1;
  for(int c_i = 0; c_i < 50; c_i++) {
    if(vws[c_i].size() == 0) {
      for(int i = 0; i < w + 1; i++) {
        for(int j = 0; j < c + 1; j++) {
          dp[c_i + 1][i][j] = dp[c_i][i][j];
        }
      }
      continue;
    }
    vector<vector<vector<int>>> dp2(vws[c_i].size() + 1);
    for(int i = 0; i < vws[c_i].size() + 1; i++) {
      dp2[i].resize(w + 1);
      for(int j = 0; j < w + 1; j++) dp2[i][j].resize(c + 1);
    }
    for(int c_j = 0; c_j < vws[c_i].size(); c_j++) {
      for(int i = 1; i < w + 1; i++) {
        for(int j = 1; j < c + 1; j++) {
          dp2[c_j + 1][i][j] = max(dp2[c_j][i][j], dp2[c_j + 1][i - 1][j]);
          if(i >= vws[c_i][c_j].first) {
            dp2[c_j + 1][i][j] = max(dp2[c_j + 1][i][j], (dp[c_i][i - vws[c_i][c_j].first][j - 1] + vws[c_i][c_j].second));
            dp2[c_j + 1][i][j] = max(dp2[c_j + 1][i][j], (dp2[c_j][i - vws[c_i][c_j].first][j] + vws[c_i][c_j].second));
          }
        }
      }
      cnt++;
    }
    for(int i = 0; i < w + 1; i++) {
      for(int j = 0; j < c + 1; j++) {
        dp[c_i + 1][i][j] = max(dp[c_i][i][j], dp2[vws[c_i].size()][i][j]);
      }
    }
  }
  cout << dp[50][w][c] << endl;
  return 0;
}
