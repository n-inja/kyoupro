#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int n;
vector<long long> a;

bool f(int j) {
  if (j < 0)
    return false;
  long long s = a[j];
  for (int i = 0; i < n; i++) {
    if (i == j)
      continue;
    if (s * 2 >= a[i]) {
      s += a[i];
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  if (!f(n - 1)) {
    cout << 0 << endl;
    return 0;
  }
  int l = -1, r = n - 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[r] <= a[i])
      ans++;
  }
  cout << ans << endl;

  return 0;
}
