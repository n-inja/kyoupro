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
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n / 2; i++)
    ans += a[i * 2 + 1] - a[i * 2];
  cout << ans << endl;
  return 0;
}
