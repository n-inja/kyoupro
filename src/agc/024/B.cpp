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
  vector<int> p(n);
  int ans = 0;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  map<int, int> mp;
  for (int i = n - 1; i >= 0; i--) {
    mp[p[i]] = mp[p[i] + 1] + 1;
    ans = max(ans, mp[p[i]]);
  }
  cout << n - ans << endl;
  return 0;
}
