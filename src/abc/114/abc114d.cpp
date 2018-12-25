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

map<int, int> q;

void f(int a) {
  if (a <= 1)
    return;
  if (a % 2 == 0) {
    q[2]++;
    f(a / 2);
    return;
  }
  for (int i = 3; i <= a; i += 2) {
    if (a % i == 0) {
      q[i]++;
      f(a / i);
      return;
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    f(i);
  long long ans = 0;
  long long nums[5] = {2, 4, 14, 24, 74};
  long long b[5] = {0};
  for (auto &it : q) {
    for (int i = 0; i < 5; i++) {
      if (it.second >= nums[i])
        b[i]++;
    }
  }
  ans += b[4];
  ans += b[3] * (b[0] - 1);
  ans += b[2] * (b[1] - 1);
  ans += b[1] * (b[1] - 1) * (b[0] - 2) / 2;
  cout << ans << endl;

  return 0;
}
