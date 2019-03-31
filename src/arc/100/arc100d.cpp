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
vector<long long> a;

long long f(long long x) {
  if (x == 0)
    return a.size() * 2;
  long long minSum = 0, maxSum = 0;
  long long sum = 0;
  int split = 0;
  for (int i = 0; i < a.size(); i++) {
    if (sum + a[i] > x) {
      minSum = min(minSum, sum);
      maxSum = max(maxSum, sum);
      split++;
      sum = a[i];
    } else if (sum + a[i] == x) {
      minSum = min(minSum, sum + a[i]);
      maxSum = max(maxSum, sum + a[i]);
      split++;
      sum = 0;
    } else {
      sum += a[i];
    }
  }
  return split + 1;
}
long long g(long long x) {
  if (x == 0)
    return a.size() * 2;
  long long minSum = 0, maxSum = 0;
  long long sum = 0;
  int split = 0;
  for (int i = 0; i < a.size(); i++) {
    if (sum + a[i] > x) {
      minSum = min(minSum, sum);
      maxSum = max(maxSum, sum);
      split++;
      sum = a[i];
    } else if (sum + a[i] == x) {
      minSum = min(minSum, sum + a[i]);
      maxSum = max(maxSum, sum + a[i]);
      split++;
      sum = 0;
    } else {
      sum += a[i];
    }
  }
  return split + 1;
}

int main() {
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long minX = 0, maxX = 1000000000000000ll;
  while (maxX - minX > 1) {
    long long mm = (minX + maxX) / 2;
    if (f(mm) > 4)
      minX = mm;
    else
      maxX = mm;
  }
  cout << maxX << endl;
  return 0;
}
