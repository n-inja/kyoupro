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
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
