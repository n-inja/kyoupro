#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int f(int a, int b) {
  int ab = abs(a - b);
  return min(b, ab);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0, num = 0;
  for (int i = 0; i < n - 1; i++)
    if (num < f(a[n - 1], a[i])) {
      ans = a[i];
      num = f(a[n - 1], a[i]);
    }
  cout << a[n - 1] << " " << ans << endl;
  return 0;
}
