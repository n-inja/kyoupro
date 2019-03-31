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
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 100000;
  for (int i = 0; i <= 100; i++) {
    if (a > i || b > i || c > i)
      continue;
    int aa, bb, cc;
    int score = (i - a) / 2;
    aa = a + (i - a) / 2 * 2;
    score += (i - b) / 2;
    bb = b + (i - b) / 2 * 2;
    score += (i - c) / 2;
    cc = c + (i - c) / 2 * 2;
    if ((i * 3 - aa - bb - cc) % 2 == 1)
      continue;
    score += (i * 3 - aa - bb - cc) / 2;
    ans = min(ans, score);
  }
  cout << ans << endl;
  return 0;
}
