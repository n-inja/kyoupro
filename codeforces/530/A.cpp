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
  int w, h;
  cin >> w >> h;
  int u1, d1, u2, d2;
  cin >> u1 >> d1 >> u2 >> d2;
  for (int i = h; i > 0; i--) {
    w += i;
    if (i == d1) {
      w -= u1;
      w = max(w, 0);
    }
    if (i == d2) {
      w -= u2;
      w = max(w, 0);
    }
  }
  cout << w << endl;

  return 0;
}
