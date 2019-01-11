#include <algorithm>
#include <bitset>
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
  for (int i = 0; i < n; i++) {
    long long l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
      cout << d << endl;
    } else {
      cout << ((r + d) / d * d) << endl;
    }
  }
  return 0;
}
