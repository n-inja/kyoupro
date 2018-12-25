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

int keta(int a, int k) {
  for (int i = 0; i < k; i++)
    a /= 10;
  return a % 10;
}

int s(int a) {
  int ret = 0;
  for (int i = 0; i < 7; i++) {
    ret += keta(a, i);
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  int ans = 100000000;
  for (int i = 1; i < n; i++) {
    ans = min(ans, s(i) + s(n - i));
  }
  cout << ans << endl;
  return 0;
}
