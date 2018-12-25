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
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<long long, int> mp;
  mp[0] = 1;
  long long ans = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum = (sum + a[i]) % m;
    ans += mp[sum];
    mp[sum] += 1;
  }
  cout << ans << endl;
  return 0;
}
