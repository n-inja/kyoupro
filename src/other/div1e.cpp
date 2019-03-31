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

int main() {
  while (true) {
    int n, m, p;
    cin >> n >> m >> p;
    if (n == m && m == p && n == 0)
      break;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    long long sum = 0;
    for (int i = 0; i < n; i++)
      sum += x[i];
    sum *= (100 - p);
    if (x[m - 1] == 0)
      cout << 0 << endl;
    else
      cout << sum / x[m - 1] << endl;
  }

  return 0;
}
