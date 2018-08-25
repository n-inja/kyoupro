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

long long f(long long l, long long r) {
  if (l * r < 0)
    return min(abs(l) * 2 + r, -l + r * 2);
  return max(abs(l), abs(r));
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  set<long long> s;
  for (int i = 0; i < k; i++)
    s.insert(x[i]);
  long long ans = 100000000000;
  for (int i = k; i < n; i++) {
    auto it = s.end();
    it--;
    int l = *s.begin();
    int r = *it;
    ans = min(ans, f(l, r));
    s.erase(s.begin());
    s.insert(x[i]);
  }
  auto it = s.end();
  it--;
  ans = min(ans, f(*s.begin(), *it));
  cout << ans << endl;
  return 0;
}
