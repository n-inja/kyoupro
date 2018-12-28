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
  int m = n / 2;
  vector<long long> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  vector<long long> a(n);
  long long abef = 0, bbef = b[0];
  for (int i = 0; i < m; i++) {
    if (bbef < b[i] - abef) {
      abef += b[i] - abef - bbef;
      bbef = b[i] - abef;
    }
    a[i] = abef;
    bbef = a[n - i - 1] = b[i] - abef;
  }
  cout << a[0];
  for (int i = 1; i < n; i++)
    cout << " " << a[i];
  cout << endl;
  return 0;
}
