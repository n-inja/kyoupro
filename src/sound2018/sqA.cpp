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
  int n, t;
  cin >> n >> t;
  int ans = 0, now = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (now <= a) {
      ans += a - now;
      now = a;
    } else {
      ans += t - now + a;
      now = a;
    }
  }
  cout << ans << endl;
  return 0;
}
