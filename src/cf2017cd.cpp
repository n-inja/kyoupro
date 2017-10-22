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

int main() {
  string s;
  cin >> s;
  int b[s.size()];
  unsigned int bit = 0;
  for(int i = 0; i < s.size(); i++) {
    bit ^= 1 << (s[i] - 'a');
    b[i] = bit;
  }
  int opt[s.size() + 1] = {0};
  map<unsigned int, int> dp;
  dp[0] = 0;
  for(int i = 0; i < s.size(); i++) {
    opt[i + 1] = 100000;
    if((long long)b[i] == 0)opt[i + 1] = 1;
    for(int j = 0; j < 26; j++) {
      if((long long)(b[i] ^ (1 << j)) > 0 && dp[b[i] ^ (1 << j)] == 0) continue;
      opt[i + 1] = min(opt[i + 1], dp[b[i] ^ (1 << j)] + 1);
    }
//    cout << opt[i + 1] << endl;
    if((long long)b[i] == 0);
    else if(dp[b[i]] == 0) dp[b[i]] = opt[i + 1];
    else dp[b[i]] = min(dp[b[i]], opt[i + 1]);
  }
  cout << opt[s.size()] << endl;
  return 0;
}
