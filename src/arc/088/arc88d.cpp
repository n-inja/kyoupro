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
  vector<int> v;
  int cnt = 0;
  bool b = false;
  for(int i = 0; i < s.size(); i++) {
    if(b) {
      if(s[i] == '0') {
        cnt++;
      } else {
        if(cnt > 0) v.push_back(cnt);
        cnt = 1;
        b = false;
      }
    } else {
      if(s[i] == '1') {
        cnt++;
      } else {
        if(cnt > 0) v.push_back(cnt);
        cnt = 1;
        b = true;
      }
    }
  }
  if(cnt > 0) v.push_back(cnt);
  if(v.size() == 1) {
    cout << s.size() << endl;
    return 0;
  }
  if(v.size() == 2) {
    cout << max(v[0], v[1]) << endl;
    return 0;
  }
  int l = 0, r = v.size() - 1;
  while(r - l > 1) {
    if(v[r] < v[l]) {
      v[r - 1] += v[r];
      r--;
    } else {
      v[l + 1] += v[l];
      l++;
    }
  }
  cout << max(v[l], v[r]) << endl;
  return 0;
}
