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
  vector<string> mp(n), mp2(n);
  for (int i = 0; i < n; i++)
    cin >> mp[i];
  for (int i = 0; i < n; i++)
    mp2[i] = mp[i];

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      mp2[j] = mp[(j + i) % n];
    bool b = true;
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (mp2[j][k] != mp2[k][j])
          b = false;
    if (b)
      ans += n;
  }
  cout << ans << endl;
  return 0;
}
