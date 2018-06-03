#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n = 8, ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans = max(ans, a);
  }
  cout << ans << endl;
  return 0;
}
