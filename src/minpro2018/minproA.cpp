#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.substr(0, 3) == "yah" && s[3] == s[4])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
