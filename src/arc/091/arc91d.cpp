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
  long long ans = 0;
  for (int b = k + 1; b <= n; b++) {
    long long num = b - k;
    ans += (n / b) * num;
    if (k == 0) {
      ans += n % b;
    }
    if (k > 0 && n % b - (k - 1) > 0) {
      ans += n % b - (k - 1);
    }
  }
  cout << ans << endl;
  return 0;
}
