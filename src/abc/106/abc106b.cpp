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

int sum(int a) {
  map<int, int> mp;
  while (a > 1) {
    bool b = false;
    for (int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        mp[i]++;
        a /= i;
        b = true;
        break;
      }
    }
    if (!b) {
      mp[a]++;
      break;
    }
  }
  int ret = 1;
  for (auto it = mp.begin(); it != mp.end(); it++)
    ret *= it->second + 1;
  return ret;
}

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i += 2) {
    if (sum(i) == 8) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
