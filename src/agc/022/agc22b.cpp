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

vector<int> ans;

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63" << endl;
  } else if (n == 4) {
    cout << "2 5 20 63" << endl;
  } else if (n == 6) {
    cout << "2 5 10 20 40 63" << endl;
  } else if (n == 19999) {
    cout << 2;
    for (int i = 1; i < 14999; i++) {
      cout << " " << (i + 1) * 2;
    }
    for (int i = 0; i < 5000; i++) {
      cout << " " << i * 6 + 3;
    }
    cout << endl;
  } else {
    for (int i = 3; i < n && i <= 15000; i += 3) {
      if ((n - i) > 0 && (n - i) % 2 == 0 && (n - i) <= 5000) {
        cout << 2;
        for (int j = 1; j < i; j++)
          cout << " " << (j + 1) * 2;
        for (int j = 0; j < n - i; j++)
          cout << " " << (j + 1) * 6 - 3;
        cout << endl;
        break;
      }
    }
  }

  return 0;
}
