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
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cout << (char)('a' + i % k);
    }
    cout << endl;
  }
  return 0;
}
