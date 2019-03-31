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
  int a, b, n;
  string s;
  cin >> a >> b >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      if (a > 0)
        a--;
    } else if (s[i] == 'C') {
      if (b > 0)
        b--;
    } else {
      if (a > b) {
        if (a > 0)
          a--;
      } else if (a < b) {
        if (b > 0)
          b--;
      } else {
        if (a > 0) {
          a--;
        }
      }
    }
  }
  cout << a << endl << b << endl;
  return 0;
}
