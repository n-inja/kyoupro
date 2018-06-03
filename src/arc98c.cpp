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
  int n;
  string s;
  cin >> n >> s;
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'E')
      l++;
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'E')
      l--;
    ans = min(ans, r + l);
    if (s[i] == 'W')
      r++;
  }
  cout << ans << endl;
  return 0;
}
