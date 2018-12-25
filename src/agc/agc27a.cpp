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
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] <= x) {
      if (i == n - 1 && a[i] < x) {

      } else {
        ans++;
        x -= a[i];
      }
    }
  cout << ans << endl;
  return 0;
}
