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
  int n, k;
  cin >> n >> k;
  vector<long long> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  sort(h.begin(), h.end());
  long long ans = 10000000000LL;
  for (int i = 0; i + k - 1 < n; i++) {
    ans = min(ans, h[i + k - 1] - h[i]);
  }
  cout << ans << endl;
  return 0;
}
