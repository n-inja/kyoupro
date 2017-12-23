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
  long long ans;
  cin >> ans;
  long long mfans = 0, flans = 0;
  int num = 0;
  bool b = true;
  char ls = '+';
  for(int i = 0; i < s.size(); i++) {
    if(b) {
      num = s[i] - '0';
      b = false;
    } else {
      if(s[i] == '+' || s[i] == '*') {
        if(ls == '+') flans += num;
        else flans *= num;
        ls = s[i];
        b = true;
      } else {
        num = num * 10 + s[i] - '0';
      }
    }
  }
  if(ls == '+') flans += num;
  else flans *= num;
  
  string ss = "0+" + s + "+0";
  while(true) {
    bool bb = false;
    for(int i = 0; i < ss.size(); i++) {
      if(ss[i] == '*') {
        int k = i - 1;
        for(; k > 0; k--) if(ss[k] == '+' || ss[k] == '*') {
          k++;
          break;
        }
        int l = i + 1;
        for(; l < ss.size(); l++) if(ss[l] == '+' || ss[l] == '*') {
          l--;
          break;
        }
        int lhs = stoi(ss.substr(k, i - k));
        int rhs = stoi(ss.substr(i + 1, l - i));
        ss = ss.substr(0, k) + to_string(lhs * rhs) + ss.substr(l + 1, ss.size());
        bb = true;
        break;
      }
    }
    if(!bb) break;
  }
  num = 0;
  b = true;
  for(int i = 0; i < ss.size(); i++) {
    if(b) {
      num = ss[i] - '0';
      b = false;
    } else {
      if(ss[i] == '+') {
        mfans += num;
        b = true;
      } else {
        num = num * 10 + ss[i] - '0';
      }
    }
  }
  mfans += num;
  
  
  if(flans == ans && mfans == ans) cout << "U" << endl;
  else if(mfans == ans) cout << "M" << endl;
  else if(flans == ans) cout << "L" << endl;
  else cout << "I" << endl;

  return 0;
}
