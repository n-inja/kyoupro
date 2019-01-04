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
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  int ok = 0;
  map<int, int> l, r;
  for (int i = 0; i < n; i++) {
    int sum = 0, smin = 0;
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '(') {
        sum++;
      } else {
        sum--;
        smin = min(smin, sum);
      }
    }
    if (sum == 0 && smin == 0) {
      ok++;
    } else if (sum > 0 && smin == 0) {
      l[sum]++;
    } else if (sum < 0 && smin >= sum) {
      r[sum]++;
    }
  }
  int ans = 0;
  ans += ok / 2;
  for (auto &it : l) {
    ans += min(it.second, r[-it.first]);
  }
  cout << ans << endl;
  return 0;
}
