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
  string s;
  map<char, bool> mp;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    mp[s[i]] = true;
  if (mp['a'] && mp['b'] && mp['c'])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
