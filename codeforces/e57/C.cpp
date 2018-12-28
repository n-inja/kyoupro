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

vector<int> ans(181);

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 181; i++)
    ans[i] = 1000;
  for (int i = 3; i <= 1000; i++) {
    for (int j = 1; j <= i - 2; j++) {
      if ((180 * j) % i == 0) {
        if ((180 * j) / i > 180)
          continue;
        ans[(180 * j) / i] = min(ans[(180 * j) / i], i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cout << ans[a] << endl;
  }
  return 0;
}
