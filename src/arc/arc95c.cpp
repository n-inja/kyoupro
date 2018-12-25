#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  b = a;
  sort(b.begin(), b.end());
  int m1 = b[n / 2 - 1], m2 = b[n / 2];
  for (int i = 0; i < n; i++)
    if (a[i] <= m1)
      cout << m2 << endl;
    else
      cout << m1 << endl;
  return 0;
}
