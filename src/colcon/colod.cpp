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

int n;
int x;
vector<int> t;
int dp[5001][5001];

int main() {
  cin >> n >> x;
  t.resize(n);
  for(int i = 0; i < n; i++) cin >> t[i];
  for(int i = 0; i < 5001; i++) for(int j = 0; j < 5001; j++) dp[i][j] = 0;
  for(int i = 0; i < n; i++) {
    // k = i + 1;
    for(int j = 0; j < n; j++) {
      dp[i + 1][j] = dp[i + 1][j - 1];
      if(j == 1) {
        if(dp[i + 1][j].first < dp[i][j - 1].first + x) {
          dp[i + 1][j].first = dp[i][j - 1].first + x;
          dp[i + 1][j].second = 1;
        }
      } else {
        if(dp[i + 1][j].first < dp[i][j - 1].first + min(x, t[j] - t[dp[i][j - 1].second])) {
          dp[i + 1][j].first = dp[i][j - 1].first + min(x, t[j] - t[dp[i][j - 1].second]);
          dp[i + 1][j].second = j;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << dp[i + 1][n].first << endl;
  }

  return 0;
}
