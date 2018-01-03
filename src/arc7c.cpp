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

int bitcount(int bit) {
  int ret = 0;
  while(bit) {
    ret += bit & 1;
    bit >>= 1;
  }
  return ret;
}

bool is(int bit, int k) {
  return (bit >> k) & 1;
}

int main() {
  string s;
  cin >> s;
  int ans = s.size();
  for(int bit = 0; bit < (1 << s.size()); bit++) {
    vector<bool> b(s.size());
    for(int i = 0; i < s.size(); i++) {
      if(is(bit, i)) {
        for(int j = 0; j < s.size(); j++) {
          if(s[j] == 'o') b[(i + j) % s.size()] = true;
        }
      }
    }
    bool c = true;
    for(int i = 0; i < s.size(); i++) if(!b[i]) c = false;
    if(c) ans = min(ans, bitcount(bit));
  }
  cout << ans << endl;
  return 0;
}