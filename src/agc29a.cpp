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
  long long bn = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      bn++;
    else
      ans += bn;
  }
  cout << ans << endl;

  return 0;
}
