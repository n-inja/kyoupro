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

long long f(string s) {
  long long ret = 0, power = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'C')
      power *= 2;
    else
      ret += power;
  }
  return ret;
}

long long g(string s, char c) {
  long long ret = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c)
      ret++;
  }
  return ret;
}

string h(string s) {
  int lsi = s.size();
  for (int i = s.size() - 1; i >= 0; i--)
    if (s[i] == 'S') {
      lsi = i;
      break;
    }
  for (int i = lsi; i > 0; i--)
    if (s[i - 1] == 'C') {
      string t = s;
      swap(t[i - 1], t[i]);
      return t;
    }
  return s;
}

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    long long d;
    string s;
    cin >> d >> s;
    if (f(s) <= d) {
      cout << "Case #" << k + 1 << ": 0" << endl;
      continue;
    }
    if (g(s, 'S') > d) {
      cout << "Case #" << k + 1 << ": IMPOSSIBLE" << endl;
      continue;
    }
    int ans = 0;
    for (; f(s) > d; ans++) {
      s = h(s);
    }
    cout << "Case #" << k + 1 << ": " << ans << endl;
  }
  return 0;
}
