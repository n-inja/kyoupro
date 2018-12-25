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

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> v, dp;
  v.resize(n);
  dp.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = n - 1; i >= 0; i--) {
    int id = i;
    for(int j = n - 1; j > i; j--) {
      if(dp[id] < dp[j] && v[i] < v[j]) id = j;
    }
    dp[i] = dp[id] + 1;
    ans = max(ans, dp[i]);
  }
  cout << n - ans << endl;
  return 0;
}
