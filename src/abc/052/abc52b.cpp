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
  int ans = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'I')
      c++;
    else
      c--;
    ans = max(c, ans);
  }
  cout << ans << endl;
  return 0;
}
