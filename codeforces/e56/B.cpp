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

bool f(string &s) {
  bool b = true;
  for (int i = 0; i * 2 < s.size(); i++) {
    if (s[i] != s[s.size() - i - 1])
      b = false;
  }
  return b;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int n = s.size();
    if (!f(s)) {
      cout << s << endl;
    } else {
      bool b = false;
      for (int i = 0; i < n; i++) {
        if (s[0] != s[i]) {
          swap(s[0], s[i]);
          cout << s << endl;
          b = true;
          break;
        }
      }
      if (!b) {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
