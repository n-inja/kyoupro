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

int diff(int a, int b) { return abs(a - b); }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (diff(a[id] * n, sum) > diff(a[i] * n, sum)) {
      id = i;
    }
  }
  cout << id << endl;
  return 0;
}
