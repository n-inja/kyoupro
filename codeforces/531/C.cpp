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
  long long x, y;
  cin >> x >> y;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  if (x > y) {
    cout << n << endl;
  } else {
    int c = 0;
    for (int i = 0; i < n; i++)
      if (v[i] <= x)
        c++;
    cout << (c + 1) / 2 << endl;
  }
  return 0;
}
