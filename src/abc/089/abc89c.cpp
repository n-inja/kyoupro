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

string b[10] = {"MAR", "MAC", "MAH", "MRC", "MRH",
                "MCH", "ARC", "ARH", "ACH", "RCH"};

int main() {
  int n;
  cin >> n;
  vector<string> names(n);
  for (int i = 0; i < n; i++)
    cin >> names[i];
  map<char, int> mp;
  for (int i = 0; i < n; i++) {
    mp[names[i][0]]++;
  }
  long long ans = 0;
  for (int i = 0; i < 10; i++) {
    long long a = 1;
    for (int j = 0; j < 3; j++)
      a *= mp[b[i][j]];
    ans += a;
  }
  cout << ans << endl;
  return 0;
}
