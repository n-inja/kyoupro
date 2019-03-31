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

int main() {
  string s;
  cin >> s;
  char c = ' ';
  int count = 0;
  vector<pair<char, int>> ps;
  for (int i = 0; i < s.size(); i++) {
    if (c != s[i]) {
      if (count > 0) {
        ps.push_back(make_pair(c, count));
      }
      c = s[i];
      count = 1;
    } else {
      count++;
    }
  }
  ps.push_back(make_pair(c, count));
  for (int i = 0; i < ps.size(); i++)
    cout << ps[i].first << ps[i].second;
  cout << endl;
  return 0;
}
