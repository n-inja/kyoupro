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
  string s;
  cin >> s;
  int imos[s.size() + 1];
  for(int i = 0; i < s.size() + 1; i++) imos[i] = 0;
  bool ch[s.size()];
  for(int i = 0; i < s.size(); i++) ch[i] = false;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '2') {
      bool c = false;
      for(int j = i + 1; j < s.size(); j++) {
        if(s[j] == '5' && !ch[j]) {
          c = true;
          ch[j] = true;
          imos[i]++;
          imos[j + 1]--;
          break;
        }
        if(j == s.size() - 1) {
          cout << -1 << endl;
          return 0;
        }
      }
      if(!c) {
        cout << -1 << endl;
        return 0;
      }
      ch[i] = true;
    } else {
      if(!ch[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for(int i = 0; i < s.size(); i++) {
    if(!ch[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int sum = 0, ans = 0;
  for(int i = 0; i < s.size() + 1; i++) {
    sum += imos[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}