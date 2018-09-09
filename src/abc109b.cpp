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
  cin >> n;
  vector<string> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  set<string> s;
  char last = w[0][0];
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (last != w[i][0]) {
      ok = false;
    }
    if (s.find(w[i]) != s.end()) {
      ok = false;
    }
    last = w[i][w[i].size() - 1];
    s.insert(w[i]);
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
