#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  long long n, c, k;
  cin >> n >> c >> k;
  vector<long long> t(n);
  for (int i = 0; i < n; i++)
    cin >> t[i];
  sort(t.begin(), t.end());
  long long size = 0;
  long long ans = 0, mint;
  for (int i = 0; i < n; i++) {
    if (size == 0) {
      size++;
      mint = t[i];
    } else {
      if (t[i] - mint <= k) {
        size++;
      } else {
        ans++;
        size = 1;
        mint = t[i];
      }
    }
    if (size == c) {
      size = 0;
      ans++;
    }
  }
  if (size > 0) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
