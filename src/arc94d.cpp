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
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    if (a * b <= 2) {
      cout << 0 << endl;
      continue;
    }
    long long c = sqrt(a * b);
    long long ans = 0;
    if (a == b) {
      ans += (a - 1) * 2;
    } else if (c * c >= a * b) {
      ans += c * 2 - 3;
    } else if (c * (c + 1) >= a * b) {
      ans += c * 2 - 2;
    } else {
      ans += c * 2 - 1;
    }
    cout << ans << endl;
  }
  return 0;
}

// 1 5
// 3 1
// 2 2
//
