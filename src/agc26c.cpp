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
int n;
string s;

int main() {
  cin >> n;
  cin >> s;
  long long ans = 0;
  int m = (1 << n);
  map<string, long long> mp;
  for (int i = 0; i < m; i++) {
    string t1, t2;
    for (int j = 0; j < n; j++)
      if (((i >> j) & 1) == 1)
        t1.push_back(s[j]);
      else
        t2.push_back(s[j]);
    mp[t1 + " " + t2]++;
  }
  int l = n * 2;
  for (int i = 0; i < m; i++) {
    string t1, t2;
    for (int j = 0; j < n; j++)
      if (((i >> j) & 1) == 1)
        t1.push_back(s[l - j - 1]);
      else
        t2.push_back(s[l - j - 1]);
    ans += mp[t1 + " " + t2];
  }

  cout << ans << endl;
  return 0;
}
