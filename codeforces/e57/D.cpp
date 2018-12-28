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
  string s;
  cin >> n >> s;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long befh = 0, befa = 0, befr = 0, befd = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'h') {
      befh += a[i];
    } else if (s[i] == 'a') {
      befa += min(a[i], befh);
      befh -= min(a[i], befh);
    } else if (s[i] == 'r') {
      befr += min(a[i], befa);
      befa -= min(a[i], befa);
    } else if (s[i] == 'd') {
      befd += min(a[i], befr);
      befr -= min(a[i], befr);
    }
  }
  cout << befd << endl;
  return 0;
}
