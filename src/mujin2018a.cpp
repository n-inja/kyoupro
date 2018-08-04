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
  if (s.substr(0, 5) == "MUJIN")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
