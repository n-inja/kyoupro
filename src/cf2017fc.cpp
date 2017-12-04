#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>

using namespace std;

bool check(int bit, int k) {
  if(((bit >> k) & 1) > 0) return true;
  return false;
}

int main() {
  int n;
  cin >> n;
  int d[13] = {0};
  for(int i = 0; i < n; i++) {
    int b;
    cin >> b;
    d[b]++;
  }
  int ans = 0;
  d[0]++;
  for(int i = (1 << 24) - 1; i >= 0; i--) {
    if((i & 1) == 0) continue;
    bool b = false;
    bool c[24] = {false};
    for(int j = 1; j < 12; j++) {
      int k = 24 - j;
      if(d[j] == 0) {
        if(((i >> j) & 1) > 0 || ((i >> k) & 1) > 0) b = true;
      } else if(d[j] == 1) {
        int c = 0;
        if(((i >> j) & 1) > 0) c++;
        if(((i >> k) & 1) > 0) c++;
        if(c != 1) b = true;
      } else {
        if(((i >> j) & 1) == 0 && ((i >> k) & 1) == 0) b = true;
        if(((i >> j) & 1) == 1 && ((i >> k) & 1) == 0) c[j] = true;
        if(((i >> j) & 1) == 0 && ((i >> k) & 1) == 1) c[k] = true;
      }
    }
    if(d[12] > 0 && ((i >> 12) & 1) == 0) continue;
    if(d[0] > 1) c[0] = true;
    if(d[12] > 1) c[12] = true;
    if(b) continue;
    int sub = 12;
    for(int j = 0; j < 24; j++) {
      if(c[j]) {
        sub = 0;
        break;
      }
      if(!check(i, j)) {
        continue;
      }
      for(int k = 1; k < 12; k++) {
        if(check(i, (j + k) % 24) || check(i, (j - k + 24) % 24)) {
          sub = min(sub, k);
          break;
        }
      }
    }

    ans = max(ans, sub);
  }
  cout << ans << endl;
  return 0;
}
