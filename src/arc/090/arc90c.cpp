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
  int n;
  cin >> n;
  vector<int> a[2];
  for(int i = 0; i < 2; i++) a[i].resize(n);
  for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
  int dp[2][n + 1];
  for(int i = 0; i < 2; i++) for(int j = 0; j < n + 1; j++) dp[i][j] = 0;
  for(int i = 0; i < n; i++) dp[0][i + 1] = dp[0][i] + a[0][i];
  for(int i = 0; i < n; i++) dp[1][i + 1] = max(dp[0][i + 1], dp[1][i]) + a[1][i];
  cout << dp[1][n] << endl;
  return 0;
}
