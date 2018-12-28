#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define P 1000000007

using namespace std;

int main() {
  int n, k;
  vector<double> r;
  double ans = 0;
  cin >> n >> k;
  r.resize(n);
  for (int i = 0; i < n; i++)
    cin >> r[i];
  sort(r.begin(), r.end());
  for (int i = n - k; i < n; i++)
    ans = (ans + r[i]) / 2;
  printf("%.6f\n", ans);
  return 0;
}