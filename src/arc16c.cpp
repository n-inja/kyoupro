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

bool is(int bit, int k) {
  return (bit >> k) & 1;
}

double f(double hit, double out) {
  hit /= 100; out /= 100;
  return hit / (1 - out) / (1 - out);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> idol(m);
  vector<int> cost(m), num(m);
  for(int i = 0; i < m; i++) {
    cin >> num[i] >> cost[i];
    idol[i].resize(num[i]);
    for(int j = 0; j < num[i]; j++) cin >> idol[i][j].first >> idol[i][j].second;
    for(int j = 0; j < num[i]; j++) idol[i][j].first--;
  }
  double dp[1 << n];
  for(int bit = 0; bit < (1 << n); bit++) dp[bit] = 1145141919;
  dp[0] = 0;
  for(int bit = 0; bit < (1 << n) - 1; bit++) {
    for(int i = 0; i < m; i++) {
      int out = 0;
      for(int j = 0; j < num[i]; j++) {
        if(is(bit, idol[i][j].first)) out += idol[i][j].second;
      }
      for(int j = 0; j < num[i]; j++) {
        if(is(bit, idol[i][j].first)) continue;
        dp[bit | (1 << idol[i][j].first)] = min(dp[bit | (1 << idol[i][j].first)], dp[bit] + 1 / f(idol[i][j].second, out) * cost[i]);
      }
    }
  }
  printf("%.9lf\n", dp[(1 << n) - 1]);
  return 0;
}