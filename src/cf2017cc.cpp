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

bool isK(string s) {
  for(int i = 0; i < s.size() / 2; i++) if(s[i] != s[s.size() - 1 - i]) return false;
  return true;
}

int main() {
  string s;
  cin >> s;
  if(isK(s)) {
    cout << 0 << endl;
    return 0;
  }
  string ss;
  for(int i = 0; i < s.size(); i++) if(s[i] != 'x') ss.push_back(s[i]);
  if(!isK(ss)) {
    cout << -1 << endl;
    return 0;
  }
  int index = s.size() - 1, ans = 0;
  for(int i = 0; i <= index; i++) {
    if(s[i] == s[index]) {
      index--;
      continue;
    }
    if(s[i] == 'x') {
      ans++;
      continue;
    }
    if(s[index] == 'x') {
      ans++;
      index--;
      i--;
      continue;
    }
  }
  cout << ans << endl;
  return 0;
}
