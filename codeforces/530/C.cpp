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

int main() {
  int n;
  string s;
  cin >> s >> n;
  int h = 0, st = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '?')
      h++;
    else if (s[i] == '*')
      st++;
  string t;
  int rest = s.size() - h * 2 - st * 2;
  s.push_back('$');

  if (rest > n) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (st > 0) {
    int rep = n - rest;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i + 1] == '?' || s[i] == '?')
        continue;
      if ((rep == 0 && s[i + 1] == '*') || s[i] == '*')
        continue;
      if (s[i + 1] == '*') {
        while (rep) {
          t.push_back(s[i]);
          rep--;
        }
      } else {
        t.push_back(s[i]);
      }
    }
    cout << t << endl;
  } else {
    int can = n - rest;
    for (int i = 0; i < s.size() - 1; i++) {
      if ((s[i + 1] == '?' && can == 0) || s[i] == '?')
        continue;
      t.push_back(s[i]);
      if (s[i + 1] == '?')
        can--;
    }
    if (t.size() == n)
      cout << t << endl;
    else
      cout << "Impossible" << endl;
  }
  return 0;
}
