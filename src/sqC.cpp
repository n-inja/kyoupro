#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool valid(string s, bool mode) {
  if (mode)
    for (int i = 0; i < s.size(); i++)
      s[i] = s[i] == '(' ? ')' : '(';
  int a = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      a++;
    else
      a--;
    if (a < 0)
      return false;
  }
  return a == 0;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (int j = 0; j < s.size(); j++)
      if (s[j] == '(')
        l++;
      else
        r++;
    if (r != l) {
      cout << "No" << endl;
      continue;
    }
    string a, b;
    int ac = 0, bc = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '(') {
        if (ac < s.size() / 4) {
          a.push_back('(');
          ac++;
        } else
          b.push_back('(');
      } else {
        if (bc < s.size() / 4) {
          b.push_back(')');
          bc++;
        } else
          a.push_back(')');
      }
    }
    if (valid(a, false) && valid(b, true))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
