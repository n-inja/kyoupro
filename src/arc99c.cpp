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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int id;
  for (int i = 0; i < n; i++)
    if (a[i] == 1)
      id = i;
  cout << (n - 1 + k - 2) / (k - 1) << endl;
  return 0;
}
