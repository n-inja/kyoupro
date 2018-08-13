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

using namespace std;

const long long P = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> x(n), y(m);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < m; i++)
    cin >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  long long dpx[100001] = {0};
  long long dpy[100001] = {0};
  dpx[0] = 0;
  dpy[0] = 0;
  long long sumx = 0;
  long long sumy = 0;
  for (int i = 1; i < n; i++) {
    dpx[i] = (dpx[i - 1] + i * (x[i] - x[i - 1])) % P;
    sumx = (sumx + dpx[i]) % P;
  }
  for (int i = 1; i < m; i++) {
    dpy[i] = (dpy[i - 1] + i * (y[i] - y[i - 1])) % P;
    sumy = (sumy + dpy[i]) % P;
  }
  cout << (sumx * sumy) % P << endl;
  return 0;
}
