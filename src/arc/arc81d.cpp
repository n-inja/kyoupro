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
  int w;
  cin >> w;
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> a;
  map<char, bool> mp;
  for(int i = 0; i < w; i++) {
    if(mp[s1[i]]) continue;
    else {
      mp[s1[i]] = true;
      if(s2[i] == s1[i]) a.push_back(0);
      else a.push_back(1);
    }
  }
  int m = a.size();

  vector<long long> dp(m);
  if(a[0] == 0) dp[0] = 3;
  else dp[0] = 6;
  for(int i = 1; i < m; i++) {
    if(a[i] == 0) {
      if(a[i - 1] == 0) {
        dp[i] = (dp[i - 1] * 2) % P;
      } else {
        dp[i] = (dp[i - 1] * 1) % P;
      }
    } else {
      if(a[i - 1] == 0) {
        dp[i] = (dp[i - 1] * 2) % P;
      } else {
        dp[i] = (dp[i - 1] * 3) % P;
      }
    }
  }
  cout << dp[m - 1] << endl;
  return 0;
}
