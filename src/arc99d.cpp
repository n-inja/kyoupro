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
int g(long long x) {
  string s = to_string(x);
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
    sum += s[i] - '0';
  return sum;
}
bool f(long long x, int k) { return x <= ((long long)pow(10, k)) * g(x); }
long long make(long long x, long long y) {
  return x * ((long long)pow(10, y)) + ((long long)pow(10, y) - 1);
}
int main() {
  int n;
  cin >> n;
  set<long long> s;
  for (int i = 0; i < 15; i++) {
    for (int j = 1; f(make(j, i), i); j++) {
      if (make(j, i) > 1000000000000000ll || make(j, i) < 0)
        break;
      s.insert(make(j, i));
    }
  }
  auto it = s.begin();
  for (int i = 0; i < n && it != s.end(); i++) {
    cout << *it << endl;
    it++;
  }

  return 0;
}
