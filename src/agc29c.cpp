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

vector<long long> a;
int n;

vector<pair<long long, int>> arr;

void push(long long b, long long m) {
  while (arr.size() > 0 && arr[arr.size() - 1].first > b) {
    arr.pop_back();
  }
  if (arr.size() == 0 || arr[arr.size() - 1].first < b) {
    arr.push_back(make_pair(b, 1));
  } else {
    arr[arr.size() - 1].second++;
    if (arr[arr.size() - 1].second >= m) {
      push(b - 1, m);
    }
  }
}

void drop(long long b, long long m) {
  while (arr.size() > 0 && arr[arr.size() - 1].first > b) {
    arr.pop_back();
  }
}

bool f(long long m) {
  if (m == 1) {
    for (int i = 1; i < n; i++)
      if (a[i] <= a[i - 1])
        return false;
    return true;
  }

  arr.clear();
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      push(a[i], m);
    } else {
      drop(a[i - 1], m);
    }
  }
  bool ret = true;
  for (auto &it : arr) {
    if (it.first <= 0)
      ret = false;
  }

  return ret;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (f(1)) {
    cout << 1 << endl;
    return 0;
  }
  if (f(2)) {
    cout << 2 << endl;
    return 0;
  }
  if (f(3)) {
    cout << 3 << endl;
    return 0;
  }

  long long mx = n;
  long long my = 0;
  while (mx - my > 1) {
    long long mm = (mx + my) / 2;

    if (f(mm)) {
      mx = mm;
    } else {
      my = mm;
    }
  }
  cout << mx << endl;

  return 0;
}
