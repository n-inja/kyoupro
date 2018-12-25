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
  string s;
  cin >> s;
  int n = s.size();
  if (s[n - 1] == '1' || s[0] == '0') {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> v;
  bool ok = true;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 2 - i])
      ok = false;
    if (s[i] == '1')
      v.push_back(i + 1);
  }
  if (!ok) {
    cout << "-1" << endl;
    return 0;
  }
  sort(v.begin(), v.end());
  int q = 1, bef = 0, par = -1;
  int m = v.size();
  for (int i = 0; i < m; i++) {
    int now = q++;
    if (par >= 0) {
      cout << par << " " << now << endl;
    }
    par = now;
    for (int j = 0; j < v[i] - bef - 1; j++) {
      cout << now << " " << q++ << endl;
    }
    bef = v[i];
  }
  int now = q++;
  cout << par << " " << now << endl;
  while (q <= n) {
    cout << now << " " << q++ << endl;
  }
  return 0;
}
