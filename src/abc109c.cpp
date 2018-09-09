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

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<long long> x(n + 1);
  for (int i = 0; i < n + 1; i++)
    cin >> x[i];
  vector<long long> y(n);
  sort(x.begin(), x.end());
  for (int i = 0; i < n; i++)
    y[i] = x[i + 1] - x[i];
  long long ans = y[0];
  for (int i = 1; i < n; i++)
    ans = gcd(ans, y[i]);
  cout << ans << endl;
  return 0;
}
