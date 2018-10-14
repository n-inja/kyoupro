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
  long long n, x;
  cin >> n >> x;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i] * b[i];
  long long maxB = b[0];
  for (int i = 1; i < n; i++)
    maxB = max(maxB, b[i]);
  ans += maxB * x;
  cout << ans << endl;
  return 0;
}
