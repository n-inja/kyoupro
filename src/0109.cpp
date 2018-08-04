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

string s;
int it = 0;

long long mdparse(string s) {
  s.push_back('$');
  long long ret = 1;
  long long tmp = 0;
  bool bef = true;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*' || s[i] == '/' || s[i] == '$') {
      if (bef) {
        ret *= tmp;
      } else {
        ret /= tmp;
      }
      bef = s[i] == '*';
      tmp = 0;
    } else {
      tmp = tmp * 10 + s[i] - '0';
    }
  }
  return ret;
}

long long parse(string s) {
  s.push_back('$');
  int b = 0;
  bool bef = true;
  long long ret = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '$' || s[i] == '+' || s[i] == '-') {
      if (bef) {
        ret += mdparse(s.substr(b, i - b));
      } else {
        ret -= mdparse(s.substr(b, i - b));
      }
      b = i + 1;
      bef = s[i] == '+';
    }
  }
  return ret;
}

long long solve() {
  string t = "";
  for (; it < s.size(); it++) {
    if (s[it] == '(') {
      it++;
      t += solve();
    } else if (s[it] == ')') {
      it++;
      return parse(t);
    } else {
      t.push_back(s[it]);
    }
  }
  return parse(t);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    s = s.substr(0, s.size() - 1);
    cout << solve() << endl;
  }
  return 0;
}
