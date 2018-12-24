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
  vector<long long> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x.begin(), x.end());
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += (x[i] - x[i - 1]) * i * (n - i);
  }
  cout << ans << endl;
  return 0;
}
