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
  int a, b;
  string s;
  cin >> a >> b >> s;
  if(s[a] == '-') {
    bool b = true;
    for(int i = 0; i < a; i++) if(s[i] < '0' || s[i] > '9') b = false;
    for(int i = 0; i < b; i++) if(s[a + 1 + i] < '0' || s[a + 1 + i] > '9') b = false;
    if(b) {
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
