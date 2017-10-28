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

#define P 1000000007

using namespace std;

bool eq(string lhs, string rhs) {
  if(lhs.size() != rhs.size()) return false;
  for(int i = 0; i < lhs.size(); i++) if(lhs[i] != '?' && rhs[i] != '?' && lhs[i] != rhs[i]) return false;
  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  string ans;
  bool b = true;
  for(int i = 0; i < s.size(); i++) ans.push_back('z');
  for(int i = 0; i < s.size(); i++) {
    if(eq(s.substr(i, t.size()), t)) {
      b = false;
      string a;
      for(int j = 0; j < i; j++) a.push_back((s[j] == '?' ? 'a' : s[j]));
      for(int j = 0; j < t.size(); j++) a.push_back(t[j]);
      for(int j = t.size() + i; j < s.size(); j++) a.push_back((s[j] == '?' ? 'a' : s[j]));
      if(a < ans) {
        ans = a;
      }
    }
  }
  if(b) cout << "UNRESTORABLE" << endl;
  else cout << ans << endl;
  return 0;
}
