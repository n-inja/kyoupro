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

long long P = 1000000007;

int main() {
  int n, K;
  cin >> n >> K;
  vector<map<int, int>> dp(n + 1);
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  dp[0][0] = 1;
  for(int k = 0; k < n; k++) {
    for(auto it = dp[k].begin(); it != dp[k].end(); it++) {
      dp[k + 1][it->first] = (dp[k + 1][it->first] + it->second) % P;
      dp[k + 1][it->first ^ a[k]] = (dp[k + 1][it->first ^ a[k]] + it->second) % P;
    }
  }

  cout << dp[n][K] << endl;
	return 0;
}
