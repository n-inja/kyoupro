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
  long long n, k;
  cin >> n >> k;
  if (k % 2 == 0) {
    long long r0 = n / k;
    long long rh = (n + k / 2) / k;
    cout << r0 * r0 * r0 + rh * rh * rh << endl;
  } else {
    cout << (n / k) * (n / k) * (n / k) << endl;
  }
  return 0;
}
