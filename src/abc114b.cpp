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

int decode(string s) {
  int ret = 0;
  ret += (s[0] - '0') * 100;
  ret += (s[1] - '0') * 10;
  ret += s[2] - '0';
  return ret;
}

int main() {
  string s;
  cin >> s;
  int diff = 10000;
  for (int i = 0; i < s.size() - 2; i++) {
    int b = decode(s.substr(i, 3));
    if (abs(b - 753) < diff) {
      diff = abs(b - 753);
    }
  }

  cout << diff << endl;
  return 0;
}
