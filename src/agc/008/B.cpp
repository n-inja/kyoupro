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
  vector<long long> a(n), sum(n + 1), psum(n + 1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
    psum[i + 1] = psum[i] + (a[i] > 0 ? a[i] : 0);
  }
  int maxId = 0;
  for (int i = 0; i <= n - k; i++) {
    if (psum[n] - (psum[maxId + k] - psum[maxId]) +
            max(sum[maxId + k] - sum[maxId], 0ll) <
        psum[n] - (psum[i + k] - psum[i]) + max(sum[i + k] - sum[i], 0ll)) {
      maxId = i;
    }
  }
  cout << psum[n] - (psum[maxId + k] - psum[maxId]) +
              max(sum[maxId + k] - sum[maxId], 0ll)
       << endl;
  return 0;
}
