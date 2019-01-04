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
  set<int> s;
  s.insert(0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    set<int> t;
    for (auto &i : s) {
      t.insert((i + a) % 360);
      t.insert((i - a + 360) % 360);
    }
    s = t;
  }
  if (s.find(0) != s.end()) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
