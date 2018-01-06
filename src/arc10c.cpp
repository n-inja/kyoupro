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

int main() {
  int n, m, y, z;
  cin >> n >> m >> y >> z;
  vector<pair<char, int>> cp(m);
  for(int i = 0; i < m; i++) cin >> cp[i].first >> cp[i].second;
  int id[26] = {0};
  for(int i = 0; i < m; i++) id[cp[i].first - 'A'] = i;
  string s;
  cin >> s;
  vector<pair<int, int>> in;
  int cnt = 0;
  int c = -1;
  for(int i = 0; i < s.size(); i++) {
    if(c == id[s[i] - 'A']) cnt++;
    else {
      in.push_back(make_pair(c, cnt));
      c = id[s[i] - 'A'];
      cnt = 1;
    }
  }
  in.push_back(make_pair(c, cnt));
  int N = in.size();
  int dp[1 << m][N];
  
  for(int i = 0; i < (1 << m); i++) for(int j = 0; j < N; j++) dp[i][j] = -1145141919;
  dp[0][0] = 0;
  
  int bit = 1 << m;
  
  for(int i = 1; i < N; i++) {
    // in[1, (N - 1)]
    for(int j = 0; j < bit; j++) {
      for(int k = 0; k < i; k++) {
        if(in[k].first == in[i].first) {
          dp[j][i] = max(dp[j][i], dp[j][k] + in[i].second * max(0, cp[in[i].first].second + y));
        } else {
          dp[j | (1 << in[i].first)][i] = max(dp[j | (1 << in[i].first)][i], dp[j][k] + cp[in[i].first].second + (in[i].second - 1) * max(0, cp[in[i].first].second + y));
        }
      }
    }
  }
  
  int ans = -1145141919;
  for(int i = 0; i < bit; i++) {
    for(int j = 0; j < N; j++) {
      if(i == (1 << m) - 1) ans = max(ans, dp[i][j] + z);
      else ans = max(ans, dp[i][j]);
    }
  }
  
  cout << ans << endl;
  
  return 0;
}