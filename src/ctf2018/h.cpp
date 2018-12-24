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
int n;
vector<long long> a;

bool solve(long long k) {
  long long adp[1001], bdp[1001];
  for (int i = 0; i <= n; i++)
    adp[i] = bdp[i] = -100000000000000;
  adp[n] = bdp[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    long long sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      adp[i] = max(adp[i], -bdp[j + 1] + (sum >= k ? 1 : -1));
      bdp[i] = max(bdp[i], -adp[j + 1] + (sum < k ? 1 : -1));
    }
  }
  return adp[0] >= 0;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long kl = -1000000000001, kr = 1000000000001;
  while (kr - kl > 1) {
    long long k = (kl + kr) / 2;
    if (solve(k)) {
      kl = k;
    } else {
      kr = k;
    }
  }
  cout << kl << endl;
  return 0;
}
