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

long long P = 998244353;

int main() {
  int n;
  string s;
  cin >> n >> s;
  long long ans = 1;
  for (int i = 'a'; i <= 'z'; i++) {
    vector<bool> v(n);
    for (int j = 0; j < n; j++)
      if (i == s[j])
        v[j] = true;
    long long l = 0, r = 0;
    for (int j = 0; j < n && v[j]; j++) {
      l++;
    }
    for (int j = n - 1; j >= 0 && v[j]; j--) {
      r++;
    }
    ans += ((l + 1) * (r + 1) - 1) % P;
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}
