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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  vector<int> v, w;
  map<char, int> mp1, mp2;
  int c = 1;
  for (int i = 0; i < n; i++) {
    if (mp1[s[i]] == 0) {
      mp1[s[i]] = c++;
    }
    v.push_back(mp1[s[i]]);
  }
  c = 1;
  for (int i = 0; i < n; i++) {
    if (mp2[t[i]] == 0) {
      mp2[t[i]] = c++;
    }
    w.push_back(mp2[t[i]]);
  }
  bool ok = true;
  for (int i = 0; i < n; i++)
    if (v[i] != w[i])
      ok = false;
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
