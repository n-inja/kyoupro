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
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    vector<long long> v(n), odd, even;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (i % 2 == 0)
        odd.push_back(v[i]);
      else
        even.push_back(v[i]);
    }
    sort(v.begin(), v.end());
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        w[i] = odd[i / 2];
      else
        w[i] = even[i / 2];
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
      if (v[i] != w[i]) {
        ans = i;
        break;
      }
    if (ans < 0) {
      cout << "Case #" << k + 1 << ": OK" << endl;
    } else {
      cout << "Case #" << k + 1 << ": " << ans << endl;
    }
  }
  return 0;
}
