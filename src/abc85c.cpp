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
  int n, y;
  cin >> n >> y;
  y /= 1000;
  bool dp[n + 1][y + 1];
  int back[n + 1][y + 1];
  for(int i = 0; i < n + 1; i++) for(int j = 0; j < y + 1; j++) dp[i][j] = false;
  for(int i = 0; i < n + 1; i++) for(int j = 0; j < y + 1; j++) back[i][j] = 0;
  dp[0][0] = true;
  for(int i = 0; i < n; i++) for(int j = 0; j < y; j++) {
    if(dp[i][j]) {
      if(j + 1 <= y) {
        dp[i + 1][j + 1] = true;
        back[i + 1][j + 1] = 1;
      }
      if(j + 5 <= y) {
        dp[i + 1][j + 5] = true;
        back[i + 1][j + 5] = 5;
      }
      if(j + 10 <= y) {
        dp[i + 1][j + 10] = true;
        back[i + 1][j + 10] = 10;
      }
    }
  }
  if(dp[n][y]) {
    int ans[11] = {0};
    int x = y;
    for(int i = n; i > 0; i--) {
      ans[back[i][x]]++;
      x -= back[i][x];
    }
    cout << ans[10] << " " << ans[5] << " " << ans[1] << endl;
  } else {
    cout << "-1 -1 -1" << endl;
  }
  
  return 0;
}
