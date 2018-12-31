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
  vector<long long> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  long long ans = 0;
  long long current = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (current > v[i]) {
      cout << -1 << endl;
      return 0;
    }
    if (current != v[i]) {
      if (v[i] > i) {
        cout << -1 << endl;
        return 0;
      }
      ans += v[i];
      current = v[i];
    }
    if (current > 0)
      current--;
  }
  cout << ans << endl;
  return 0;
}
