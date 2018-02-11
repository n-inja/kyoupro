#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
long long n, k;
vector<pair<long long, long long>> ads;
long long ans = 0;

bool ff(long long a, long long d, long long n, long long k) {
  if (n == 0)
    return true;
  return a + d * (n - 1) <= k;
}

long long f(long long t) {
  if (t == 0) {
    return 0;
  }
  ans = 0;
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    long long maxN = t, minN = 0;
    while (maxN > minN + 1) {
      long long midN = (maxN + minN) / 2;
      if (ff(ads[i].first, ads[i].second, midN, t))
        minN = midN;
      else
        maxN = midN;
    }
    ret += minN;
    if (minN == 0)
      continue;
    ans += ads[i].first * minN + minN * (minN - 1) / 2 * ads[i].second;
  }
  return ret;
}

int main() {
  cin >> k >> n;
  ads.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> ads[i].first >> ads[i].second;
  }
  long long maxT = 1000000000000000, minT = 0;
  while (maxT > minT + 1) {
    long long t = (maxT + minT) / 2;
    if (f(t) >= k) {
      maxT = t;
    } else {
      minT = t;
    }
  }
  long long kk = f(maxT);
  cout << ans - maxT * (kk - k) << endl;

  return 0;
}
