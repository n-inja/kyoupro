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
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  string s;
  for (long long i = 0; i < 33; i++) {
    if (i % 2 == 0) {
      s.push_back('0');
    } else {
      s.push_back('1');
      n -= (1 << (i - 1)) * (-2);
    }
  }
  string t;
  while (n > 0) {
    t.push_back('0' + (n % 2 == 1));
    n /= 2;
  }
  while (t.size() < s.size())
    t.push_back('0');
  string ans;
  for (long long i = 0; i < t.size(); i++) {
    ans.push_back('0' + (s[i] != t[i]));
  }
  bool b = false;
  for (int i = ans.size() - 1; i >= 0; i--) {
    b = ans[i] == '1' || b;
    if (b)
      cout << ans[i];
  }
  cout << endl;

  return 0;
}
