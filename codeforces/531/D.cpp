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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int t[3] = {0};
  for (int i = 0; i < n; i++)
    t[s[i] - '0']++;
  for (int i = 0; i < n; i++) {
    int c = s[i] - '0';
    if (t[c] > n / 3) {
      for (int j = 0; j < c; j++) {
        if (t[j] < n / 3) {
          s[i] = '0' + j;
          t[c]--;
          t[j]++;
          break;
        }
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int c = s[i] - '0';
    if (t[c] > n / 3) {
      for (int j = 2; j > c; j--) {
        if (t[j] < n / 3) {
          s[i] = '0' + j;
          t[c]--;
          t[j]++;
          break;
        }
      }
    }
  }
  cout << s << endl;
  return 0;
}
