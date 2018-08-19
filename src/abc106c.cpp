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
  int k;
  cin >> s >> k;
  bool b = k < s.size();
  int base = 0;
  for (int i = 0; i < k && i < s.size(); i++) {
    if (s[i] != '1') {
      b = false;
      base = i;
      break;
    }
  }
  if (b) {
    cout << '1' << endl;
  } else {
    cout << s[base] << endl;
  }
  return 0;
}
