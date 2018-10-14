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

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  long long n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  long long l = n * m / gcd(n, m);
  int g = gcd(n, m);
  map<long, long> mp;
  for (int i = 0; i < n; i++) {
    mp[i * m / g] = s[i];
  }
  for (int i = 0; i < m; i++) {
    if (mp[i * n / g] != 0) {
      if (mp[i * n / g] != t[i]) {
        cout << "-1" << endl;
        return 0;
      }
    } else {
      mp[i * n / g] = t[i];
    }
  }
  cout << l << endl;
  return 0;
}
