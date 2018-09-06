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
  vector<int> v;
  long long ans = 0;
  bool c = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 0) {
      c = false;
    }
  }

  if (c) {
    long long mi = 0;
    for (int i = 1; i < n; i++)
      if (a[mi] < a[i])
        mi = i;
    v.push_back(mi);
    ans = a[mi];
  } else {
    long long odd = 0, even = 0;
    vector<int> ov, ev;
    for (int i = 0; i < n; i += 2)
      if (a[i] >= 0) {
        ov.push_back(i);
        odd += a[i];
      }
    for (int i = 1; i < n; i += 2)
      if (a[i] >= 0) {
        ev.push_back(i);
        even += a[i];
      }
    if (odd > even) {
      v = ov;
      ans = odd;
    } else {
      v = ev;
      ans = even;
    }
  }

  cout << ans << endl;
  int size = n;
  vector<int> w;
  for (int i = 0; i < v[0]; i++) {
    w.push_back(1);
    size--;
  }
  int del = 0;
  for (int i = 1; i < v.size();) {
    if (v[i] - v[0] - del == 2) {
      w.push_back(2);
      size -= 2;
      del += 2;
      i++;
    } else {
      w.push_back(3);
      size -= 2;
      del += 2;
    }
  }
  while (size > 1) {
    w.push_back(size);
    size--;
  }
  cout << w.size() << endl;
  for (int i = 0; i < w.size(); i++)
    cout << w[i] << endl;

  return 0;
}
