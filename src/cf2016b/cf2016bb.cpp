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
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  int over = 0;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'c') {
      cout << "No" << endl;
    }
    if(s[i] == 'a') {
      if(cnt < a + b) {
        cnt++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
    if(s[i] == 'b') {
      if(cnt < a + b && over < b) {
        over++; cnt++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
