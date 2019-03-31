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
  int k;
  cin >> k;
  set<string> ss;
  if (s.size() < 10) {
    for (int i = 0; i < s.size(); i++)
      for (int j = i + 1; j <= s.size(); j++) {
        ss.insert(s.substr(i, j - i));
      }
    auto it = ss.begin();
    for (int i = 0; i < k - 1; i++)
      it++;
    cout << *it << endl;
  } else {
    for (int i = 0; i < s.size(); i++)
      for (int j = i + 1; j <= s.size() && j - i < 7; j++)
        ss.insert(s.substr(i, j - i));
    auto it = ss.begin();
    for (int i = 0; i < k - 1; i++)
      it++;

    cout << *it << endl;
  }
  return 0;
}
