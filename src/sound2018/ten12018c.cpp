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
  sort(v.begin(), v.end());
  if (n == 2) {
    cout << abs(v[0] - v[1]) << endl;
    return 0;
  } else if (n == 3) {
    cout << max(max(abs(v[0] - v[2]) + abs(v[1] - v[2]),
                    abs(v[2] - v[0]) + abs(v[0] - v[1])),
                abs(v[1] - v[0]) + abs(v[2] - v[0]))
         << endl;
    return 0;
  }
  if (n % 2 == 0) {
    vector<long long> up, down;
    for (int i = 0; i < n / 2 - 1; i++) {
      down.push_back(v[i]);
      up.push_back(v[n - 1 - i]);
    }
    long long mi = v[n / 2 - 1], mm = v[n / 2];
    long long ans = (mm - mi) * (n - 1);
    for (int i = 0; i < down.size(); i++) {
      ans += (mi - down[i]) * 2;
    }
    for (int i = 0; i < up.size(); i++) {
      ans += (up[i] - mm) * 2;
    }
    cout << ans << endl;
  } else {
    vector<long long> up, down;
    int mii = n / 2 - 1, mmi = n / 2;
    for (int i = 0; i < mii; i++) {
      down.push_back(v[i]);
    }
    for (int i = n - 1; i > mmi; i--) {
      up.push_back(v[i]);
    }
    long long ans1 = (v[mmi] - v[mii]) * (n - 2);
    for (int i = 0; i < down.size(); i++) {
      ans1 += (v[mii] - down[i]) * 2;
    }
    for (int i = 0; i < up.size(); i++) {
      ans1 += (up[i] - v[mmi]) * 2;
    }
    up.clear();
    down.clear();
    mii = n / 2;
    mmi = n / 2 + 1;
    for (int i = 0; i < mii; i++) {
      down.push_back(v[i]);
    }
    for (int i = n - 1; i > mmi; i--) {
      up.push_back(v[i]);
    }
    long long ans2 = (v[mmi] - v[mii]) * (n - 2);
    for (int i = 0; i < down.size(); i++) {
      ans2 += (v[mii] - down[i]) * 2;
    }
    for (int i = 0; i < up.size(); i++) {
      ans2 += (up[i] - v[mmi]) * 2;
    }
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}
