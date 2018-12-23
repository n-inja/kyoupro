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
  string s;
  cin >> s;
  int n = s.size();
  map<long long, char> mp;
  string t = s;
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) {
      t[n - 2 - i * 2] = s[i];
    }
    for (int i = 0; i < n / 2; i++) {
      t[i * 2 + 1] = s[i + n / 2];
    }
  } else {
    for (int i = 0; i <= n / 2; i++) {
      t[n - 1 - i * 2] = s[i];
    }
    for (int i = 0; i < n / 2; i++) {
      t[i * 2 + 1] = s[i + (n + 1) / 2];
    }
  }
  cout << t << endl;
  return 0;
}
