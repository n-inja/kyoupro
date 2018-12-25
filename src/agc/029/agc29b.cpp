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
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  map<long long, int> mp;
  for (int i = 0; i < n; i++)
    mp[a[i]]++;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (mp[a[i]] == 0)
      continue;
    mp[a[i]]--;
    int k = 0, b = a[i];
    while (b > 0) {
      k++;
      b >>= 1;
    }
    if (mp[(1 << k) - a[i]] > 0) {
      mp[(1 << k) - a[i]]--;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
