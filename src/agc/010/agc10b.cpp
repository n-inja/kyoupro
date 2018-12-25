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
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  long long num = sum / ((n + 1) * n / 2);
  if (sum % ((n + 1) * n / 2) != 0) {
    cout << "NO" << endl;
    return 0;
  }
  long long m = 0;
  for (int i = 0; i < n; i++) {
    int next = (i + 1 + n) % n;
    if ((-a[next] + a[i] + num) < 0 || (-a[next] + a[i] + num) % n != 0) {
      cout << "NO" << endl;
      return 0;
    }
    m += (-a[next] + a[i] + num) / n;
  }
  if (m == num) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
