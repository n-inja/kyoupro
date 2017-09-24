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

vector<long long> dp;
int n, m;
vector<pair<int, int>> p;

long long f(int bit) {
  if(dp[bit] > 0) return dp[bit];
//  cout << bit << endl;
  long long ans = 0;
  set<int> s;
  for(int i = 0; i < n; i++) if(((bit >> i) & 1) == 1) s.insert(i);
  if(s.size() <= 1) {
    dp[bit] = 1;
    return dp[bit];
  }
  for(int i = 0; i < n; i++) {
    if(((bit >> i) & 1) == 1) {
      bool b = false;
      for(int j = 0; j < m; j++) {
        if(p[j].first == i && s.find(p[j].second) != s.end()) {
          b = true;
        }
      }
      if(b) continue;
      ans += f(bit ^ (1 << i));
    }
  }
  dp[bit] = ans;
  return dp[bit];
}

int main() {
  cin >> n >> m;
  p.resize(m);
  for(int i = 0; i < m; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first--; p[i].second--;
  }
  dp.resize(1 << n);
  cout << f((1 << n) - 1) << endl;

  return 0;
}
