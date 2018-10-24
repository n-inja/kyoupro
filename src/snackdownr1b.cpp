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

bool hand[350] = {0};

int main() {
  int t;
  cin >> t;
  hand['d'] = false;
  hand['f'] = false;
  hand['j'] = true;
  hand['k'] = true;
  for (int _ = 0; _ < t; _++) {
    int n, ans = 0;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int a = 0;
      if (mp[s] > 0) {
        ans += mp[s] / 2;
      } else {
        bool b = hand[s[0]];
        a += 2;
        for (int i = 1; i < s.size(); i++) {
          if (b == hand[s[i]]) {
            a += 4;
          } else {
            a += 2;
          }
          b = hand[s[i]];
        }
        mp[s] = a;
        ans += a;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
