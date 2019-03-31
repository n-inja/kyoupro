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
long long r, c, b;
vector<long long> m, s, p;

bool f(long long t) {
  vector<long long> bits(c);
  for (int i = 0; i < c; i++) {
    if (t > p[i]) {
      bits[i] += min(m[i], (t - p[i]) / s[i]);
    }
  }
  sort(bits.begin(), bits.end());
  long long bit = 0;
  for (int i = 0; i < r; i++) {
    bit += bits[c - 1 - i];
  }
  return bit >= b;
}

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    cin >> r >> b >> c;
    m.resize(c);
    s.resize(c);
    p.resize(c);
    for (int i = 0; i < c; i++)
      cin >> m[i] >> s[i] >> p[i];
    long long minT = 0, maxT = 100000000000;
    while (maxT - minT > 1) {
      long long mm = (minT + maxT) / 2;
      if (f(mm)) {
        maxT = mm;
      } else {
        minT = mm;
      }
    }
    cout << "Case #" << k + 1 << ": " << maxT << endl;
  }
  return 0;
}
