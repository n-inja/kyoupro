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
  bool b = true;
  string ans = "AKIHABARA";
  int j = 0;
  for(int i = 0; i < ans.size(); i++) {
    if(j >= s.size()) {
      if(i == ans.size() - 1) {
        break;
      } else {
        b = false;
        break;
      }
    }
    if(s[j] == ans[i]) j++;
    else if(ans[i] == 'A') continue;
    else b = false;
  }
  if(s.size() != j) {
    b = false;
  }
  if(b) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
