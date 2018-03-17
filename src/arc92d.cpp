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

int count(vector<long long>::iterator begin, vector<long long>::iterator end,
          long long val) {
  if (end == begin)
    return 0;
  auto it = lower_bound(begin, end, val);
  return end - it;
}

int main() {
  int n;
  long long l1 = 1, l2 = 2;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  long long ans = 0;
  for (int k = 29; k >= 0; k--) {
    for (int i = 0; i < n; i++) {
      if (a[i] >= (2 << k))
        a[i] -= (2 << k);
      if (b[i] >= (2 << k))
        b[i] -= (2 << k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long c = 0;
    for (int i = 0; i < n; i++) {
      if ((a[i] & (1 << k)) > 0) {
        auto en = lower_bound(b.begin(), b.end(), l1 << k);
        c += (en - b.begin()) - count(b.begin(), en, (l2 << k) - a[i]);
        c += count(en, b.end(), ((l1 << k) | (l2 << k)) - a[i]);
      } else {
        auto en = lower_bound(b.begin(), b.end(), l1 << k);
        c += count(b.begin(), en, (l1 << k) - a[i]);
        c += (b.end() - en) - count(en, b.end(), (l2 << k) - a[i]);
      }
    }
    if (c % 2 == 1)
      ans |= (l1 << k);
  }
  cout << ans << endl;
  return 0;
}
