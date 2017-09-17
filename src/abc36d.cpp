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
vector<vector<int>> p;
vector<bool> c;
vector<pair<long long, long long>> dp;

void dfs(int n) {
  if(c[n]) return;
  c[n] = true;
  for(int i = 0; i < p[n].size(); i++) {
    if(!c[p[n][i]]) dfs(p[n][i]);
  }
  int cnt = 0;
  for(int i = 0; i < p[n].size(); i++) {
    if(dp[p[n][i]].first >= 0) cnt++;
  }
  if(cnt == 0) dp[n] = make_pair(1, 1);
  else {
    dp[n].first = 1;
    dp[n].second = 1;
    for(int i = 0; i < p[n].size(); i++) {
      if(dp[p[n][i]].first >= 0) {
        dp[n].first = (dp[n].first * (dp[p[n][i]].first + dp[p[n][i]].second) % 1000000007) % 1000000007;
        dp[n].second = (dp[n].second * dp[p[n][i]].first) % 1000000007;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  c.resize(n);
  dp.resize(n);
  p.resize(n);
  for(int i = 0; i < n; i++) dp[i].first = -1;
  for(int i = 0; i < n; i++) dp[i].second = -1;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  dfs(0);
  cout << (dp[0].first + dp[0].second) % 1000000007 << endl;
  return 0;
}
