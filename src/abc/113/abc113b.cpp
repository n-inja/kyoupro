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
  int t, a;
  cin >> t >> a;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  int id = 0;
  double mindiff = 11000000;
  for (int i = 0; i < n; i++) {
    double tt = t - 0.006 * h[i];
    double fs = fabs(tt - a);
    if (mindiff > fs) {
      mindiff = fs;
      id = i;
    }
  }
  cout << id + 1 << endl;
  return 0;
}
