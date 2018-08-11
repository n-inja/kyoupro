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
  if (s[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  int c = 0;
  for (int i = 2; i < s.size() - 1; i++) {
    if (s[i] == 'C')
      c++;
  }
  if (c != 1) {
    cout << "WA" << endl;
    return 0;
  }
  c = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      c++;
  if (c != 2) {
    cout << "WA" << endl;
  } else {
    cout << "AC" << endl;
  }
  return 0;
}
