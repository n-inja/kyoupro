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

bool solve() {
  int n;
  cin >> n;
  if (n == 0)
    return false;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  reverse(s.begin(), s.end());
  vector<long long> v;
  int indent = 0;
  for (int i = 0; i < n; i++) {
    int ind = 0;
    for (; s[i][ind] == '.'; ind++)
      ;
    if (indent < ind) {
      for (int j = 0; j < ind - indent; j++)
        v.push_back(-1);
    }
    indent = ind;

    if (s[i][ind] == '+' || s[i][ind] == '*') {
      long long ret = (s[i][ind] == '+') ? 0 : 1;
      while (v[v.size() - 1] >= 0) {
        if (s[i][ind] == '+') {
          ret += v[v.size() - 1];
        } else {
          ret *= v[v.size() - 1];
        }
        v.pop_back();
      }
      v.pop_back();
      v.push_back(ret);
    } else {
      v.push_back(s[i][ind] - '0');
    }
  }
  cout << v[0] << endl;
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}
