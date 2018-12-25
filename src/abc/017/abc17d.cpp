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
  int n, m;
  cin >> n >> m;
  vector<int> f(n), p(m + 1);
  for(int i = 0; i < n; i++) cin >> f[i];
  vector<long long> dp(n + 1);
  dp[0] = 1;
  vector<long long> sum(n + 2);
  sum[0] = 0;
  sum[1] = 1;
  int l = 0;
  for(int i = 1; i < n + 1; i++) {
    l = max(l, p[f[i - 1] - 1]);
    dp[i] = (sum[i] - sum[l] + P) % P;
    p[f[i - 1] - 1] = i;
    sum[i + 1] = (sum[i] + dp[i]) % P;
  }
//  for(int i = 0; i < n; i++) cout << dp[i] << endl;
  cout << dp[n] << endl;
}
