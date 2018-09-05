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
  int n, a, b;
  cin >> n >> a >> b;
  swap(a, b);
  int m = n;
  vector<int> v(b);
  if (n < a) {
    cout << -1 << endl;
    return 0;
  }
  v[0] = a;
  n -= a;
  for (int i = 1; i < b; i++) {
    if (n < 1) {
      cout << -1 << endl;
      return 0;
    }
    v[i] = 1;
    n--;
  }
  for (int i = 1; i < b; i++) {
    if (n > 0) {
      if (n > b - 1) {
        v[i] = b;
        n -= b - 1;
      } else {
        v[i] += n;
        n = 0;
      }
    }
  }
  if (n > 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans(m);
  int c = 0;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < v[i]; j++) {
      ans[c + j] = c + v[i] - j;
    }
    c += v[i];
  }
  cout << ans[0];
  for (int i = 1; i < m; i++) {
    cout << " " << ans[i];
  }
  cout << endl;

  return 0;
}
