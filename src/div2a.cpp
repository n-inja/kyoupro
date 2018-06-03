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

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  map<int, int> mp;
  mp[a]++;
  mp[b]++;
  mp[c]++;
  if (mp[5] == 2 && mp[7] == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
