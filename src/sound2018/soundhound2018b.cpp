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
  int w;
  cin >> w;
  string ret = "";
  for (int i = 0; i < (s.size() + w - 1) / w; i++) {
    ret += s[i * w];
  }
  cout << ret << endl;
  return 0;
}
