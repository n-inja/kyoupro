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

const long long PRIME = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  vector<long long> dp(n);
  int lid = 0;
  dp[0] = v[0];
  if(dp[0] > n) {
    dp[0] = 0;
    lid++;
  }
  for(int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + v[i];
    while(dp[i] > n) {
      dp[i] -= v[lid++];
      if(dp[i] == 0) continue;
    }
  //  cout << dp[i] << endl;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) if(dp[i] == n) ans++;
  cout << ans << endl;
  return 0;
}
