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
long long n, c;
int main() {
  cin >> n >> c;
  vector<pair<long long, long long>> xv(n);
  for (int i = 0; i < n; i++) {
    cin >> xv[i].first >> xv[i].second;
  }
  long long ans = 0;
  long long rsum = 0, lsum = 0;
  long long rmax[100001] = {0}, lmax[100001] = {0};
  rmax[0] = max(0ll, xv[0].second - xv[0].first);
  rsum += xv[0].second;
  for (int i = 1; i < n; i++) {
    rsum += xv[i].second;
    rmax[i] = max(rmax[i - 1], rsum - xv[i].first);
  }
  lmax[n - 1] = max(0ll, xv[n - 1].second - (c - xv[n - 1].first));
  lsum += xv[n - 1].second;
  for (int i = 1; i < n; i++) {
    lsum += xv[n - 1 - i].second;
    lmax[n - 1 - i] = max(lmax[n - i], lsum - (c - xv[n - 1 - i].first));
  }
  for (int i = 0; i < n; i++)
    ans = max(ans, max(rmax[i], lmax[i]));

  rsum = 0;
  lsum = 0;
  for (int i = 0; i < n; i++)
    rsum += xv[i].second;
  // right * 2 + left
  long long lmaxmax = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1)
      lmaxmax = max(lmaxmax, lmax[i + 1]);
    ans = max(ans, lmaxmax + rsum - xv[i].first * 2);
    rsum -= xv[i].second;
  }
  lsum = 0;
  rsum = 0;
  for (int i = 0; i < n; i++)
    lsum += xv[i].second;
  // left * 2 + right
  long long rmaxmax = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0)
      rmaxmax = max(rmaxmax, rmax[i - 1]);
    ans = max(ans, rmaxmax + lsum - (c - xv[i].first) * 2);
    lsum -= xv[i].second;
  }
  cout << ans << endl;
  return 0;
}
