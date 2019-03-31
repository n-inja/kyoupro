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

const double pi = 3.141592653589793238462643383279;

int main() {
  string s;
  cin >> s;
  bool b = false;
  if(s[0] != s[1]) b = true;
  if(s[1] == s[2]) b = true;
  if(s[2] != s[3]) b = true;
  if(b) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
