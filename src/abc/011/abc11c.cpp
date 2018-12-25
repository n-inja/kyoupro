#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define P 1000000007

using namespace std;

int main() {
  int n;
  int ng[3];
  cin >> n >> ng[0] >> ng[1] >> ng[2];
  int num = n;
  if (n == ng[0] || n == ng[1] || n == ng[2]) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < 100; i++) {
    bool b[3] = {};
    for (int j = 0; j < 3; j++) {
      if (ng[j] >= num - 3 && ng[j] < num)
        b[num - ng[j] - 1] = true;
    }
    for (int j = 2; j >= 0; j--) {
      if (!b[j]) {
        num -= j + 1;
        if (num <= 0) {
          cout << "YES" << endl;
          return 0;
        }
        break;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
