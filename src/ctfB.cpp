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

bool is(string s) {
  for(int i = 0; i < s.size() / 2; i++) {
    if(s[i] != s[s.size() - 1 - i]) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  for(int i = 0; i <= s.size(); i++) {
    string t = s.substr(0, i);
    string ss = s;
    for(int j = 0; j < t.size(); j++) ss.push_back(t[t.size() - 1 - j]);
    if(is(ss)) {
      cout << i << endl;
      return 0;
    }
  }
	return 0;
}
