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
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    b[i] = a[i] % 2;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (b[i]) {
      if (v.size() && v[v.size() - 1] != i % 2) {
        v.pop_back();
      } else {
        v.push_back(i % 2);
      }
    }
  }
  if (v.size() == 0) {
    cout << "YES" << endl;
    return 0;
  }
  v.clear();
  for (int i = 0; i < n; i++) {
    if (!b[i]) {
      if (v.size() && v[v.size() - 1] != i % 2) {
        v.pop_back();
      } else {
        v.push_back(i % 2);
      }
    }
  }
  if (v.size() == 0) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
