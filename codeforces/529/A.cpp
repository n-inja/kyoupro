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
  string s;
  cin >> s;
  string t;
  int c = 0;
  for (int i = 0; i < s.size(); i += c) {
    t.push_back(s[i]);
    c++;
  }
  cout << t << endl;
  return 0;
}
