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
  if(s[0] == s[1] && s[1] == s[2]) cout << "Yes" << endl;
  else if(s[1] == s[2] && s[2] == s[3]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
