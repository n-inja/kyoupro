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
  long long sum = 0, lsum = 0, rsum = 0, ans = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  lsum = sum;
  map<long long, int> mp;
  mp[0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    lsum -= a[i];
    ans += mp[sum - lsum];
    rsum += a[i];
    mp[rsum]++;
  }
  cout << ans << endl;
  return 0;
}
