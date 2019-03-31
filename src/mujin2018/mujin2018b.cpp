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
  int a;
  string s;
  cin >> a >> s;
  bool b = (a == 0);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      a++;
    } else {
      a--;
      if (a == 0)
        b = true;
    }
  }
  if (b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
