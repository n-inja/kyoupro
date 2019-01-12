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
  string s;
  cin >> s;
  int n = s.size();
  int lb = n;
  int lc = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == '[') {
      lb = i;
      break;
    }
  }
  for (int i = lb; i < n; i++) {
    if (s[i] == ':') {
      lc = i;
      break;
    }
  }
  int rb = 0;
  int rc = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ']') {
      rb = i;
      break;
    }
  }
  for (int i = rb; i >= 0; i--) {
    if (s[i] == ':') {
      rc = i;
      break;
    }
  }
  if (rc == 0 || rb == 0 || lc == n || lb == n || (rc == lc) || (rb < lb)) {
    cout << -1 << endl;
    return 0;
  } else {
    int ans = 4;
    for (int i = lc + 1; i < rc; i++) {
      if (s[i] == '|')
        ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
