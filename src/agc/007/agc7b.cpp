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
  long long k[20202];
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int c = 1;
  for (int i = 0; i < n; i++) {
    k[p[i] - 1] = c++;
  }
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = k[i] + n * i;
    b[i] = k[i] - n * i + n * n;
  }
  cout << a[0];
  for (int i = 1; i < n; i++)
    cout << " " << a[i];
  cout << endl;
  cout << b[0];
  for (int i = 1; i < n; i++)
    cout << " " << b[i];
  cout << endl;

  return 0;
}
