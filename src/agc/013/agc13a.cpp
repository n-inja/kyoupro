#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b;
  for (int i = 1; i < n; i++)
    if (a[i] > a[i - 1])
      b.push_back(1);
    else if (a[i] < a[i - 1])
      b.push_back(-1);
  long long ans = 1;
  for (int i = 1; i < b.size(); i++) {
    if (b[i] * b[i - 1] < 0) {
      ans++;
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
