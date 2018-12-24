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
  int n = s.size();
  long long ans = 0;
  char now = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] <= now) {
      now = s[i];
      ans++;
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
