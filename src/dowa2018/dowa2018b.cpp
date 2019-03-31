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
  vector<int> bit(50);
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  vector<long long> v;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      long long b = s[j] - s[i];
      v.push_back(b);
      int c = 0;
      while (b > 0) {
        if (b % 2 == 1)
          bit[c]++;
        c++;
        b >>= 1;
      }
    }

  long long ans = 0;
  long long mask = 0;
  int top = 0;
  for (int i = 49; i >= 0; i--) {
    if (bit[i] >= k) {
      ans = 1LL << i;
      mask = 1LL << i;
      top = i;
      break;
    }
  }

  for (int i = top - 1; i >= 0; i--) {
    int cnt = 0;
    for (int j = 0; j < v.size(); j++) {
      if ((v[j] & mask) == 0 || ((v[j] & mask) ^ mask) > 0)
        continue;
      if ((v[j] & (1LL << i)) > 0)
        cnt++;
    }
    if (cnt >= k) {
      mask |= (1LL << i);
      ans |= (1LL << i);
    }
  }
  cout << ans << endl;
  return 0;
}
