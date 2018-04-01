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
int n;
vector<int> a;

long long cost(int i, int j) { return abs(a[i] - a[j]); }

int main() {
  cin >> n;
  a.resize(n + 2);
  a[0] = a[n + 1] = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i + 1];
  long long sum = 0;
  for (int i = 0; i < n + 1; i++)
    sum += cost(i, i + 1);
  for (int i = 0; i < n; i++) {
    cout << sum - cost(i, i + 1) - cost(i + 1, i + 2) + cost(i, i + 2) << endl;
  }
  return 0;
}
