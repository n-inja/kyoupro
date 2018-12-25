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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) {
      cout << "No" << endl;
    } else if (b > d) {
      cout << "No" << endl;
    } else if (b < c) {
      cout << "Yes" << endl;
    } else if (b == d) {
      long long rest = a - (a / b) * b;
      if (rest <= c) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      long long rest = a - (a / b) * b;
      if (rest > c) {
        cout << "No" << endl;
      } else {
        if (gcd(d - b, b) >= b - c)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
      }
    }
  }
  return 0;
}
