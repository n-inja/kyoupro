#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool f(string s) {
  bool ret = true;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i])
      ret = false;
  }
  return ret;
}

int main() {
  string s;
  cin >> s;
  int ans = 10000000;
  for (int i = 0; i <= s.size(); i++) {
    string ss = s.substr(0, i);
    reverse(ss.begin(), ss.end());
    string ns = s + ss;
    if (f(ns)) {
      ans = min(ans, (int)ss.size());
    }
  }
  cout << ans << endl;
  return 0;
}
