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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0, bef = -1, c = 0;
  a.push_back(1000);
  for (int i = 0; i <= n; i++) {
    if (bef == a[i]) {
      c++;
    } else {
      ans += c / 2;
      c = 1;
      bef = a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
