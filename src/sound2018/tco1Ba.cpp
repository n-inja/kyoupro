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

class LineOff {
public:
  string t;
  LineOff() {}
  int f() {
    if (t.size() <= 1)
      return 0;
    int ret = 0;
    for (int i = 0; i < t.size() - 1; i++) {
      if (t[i] == t[i + 1]) {
        t = t.substr(0, i) + t.substr(i + 2, t.size() - (i + 2));
        ret += f() + 1;
        break;
      }
    }
    return ret;
  }
  int movesToDo(string s) {
    t = s;
    return f();
  }
};

int main() {
  LineOff l;
  cout << l.movesToDo("wasitacarooracatisaw") << endl;
  return 0;
}
