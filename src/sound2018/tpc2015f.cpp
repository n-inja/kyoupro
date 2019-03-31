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
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<int> dp1, dp2;
  dp1.resize(s.size());
  dp2.resize(s.size());
  if(s[0] == '0') dp1[0] = 1;
  if(s[0] == '0') dp2[0] = 0;
  for(int i = 1; i < s.size(); i++) {
    if(s[i] == '0') {
      dp1[i] = max((dp1[i - 1] + 1), dp2[i - 1]);
      dp2[i] = dp2[i - 1];
    } else if(s[i] == '9') {
      dp1[i] = dp1[i - 1];
      dp2[i] = max((dp2[i - 1] + 1), dp1[i - 1]);
    } else if(s[i] == '1') {
      dp1[i] = max(dp1[i - 1], dp2[i - 1]);
      dp2[i] = max(dp2[i - 1], dp1[i - 1]);
    } else {
      dp1[i] = max(dp1[i - 1], dp2[i - 1]);
      dp2[i] = max(dp1[i - 1], dp2[i - 1]);
    }
  }
  int ans = 0;
  for(int i = 0; i < s.size(); i++) {
    ans = max(ans, dp1[i]);
    ans = max(ans, dp2[i]);
//    cout << dp1[i] << " " << dp2[i] << endl;
  }
  cout << ans << endl;
  return 0;
}
