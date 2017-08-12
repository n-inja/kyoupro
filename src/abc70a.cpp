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

int main() {
  string s;
  cin >> s;
  bool b = false;
  for(int i = 0; i < s.size()/2; i++) {
    if(s[i] != s[s.size() - 1 - i]) b = true;
  }
  if(b) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
