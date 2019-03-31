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

string c = "RGBY";

int main() {
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> mp(h);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      mp[i].push_back(c[((i + j) / d) % 2 + (((i - j + 2000) / d) % 2) * 2]);
    }
  for (int i = 0; i < h; i++)
    cout << mp[i] << endl;
  return 0;
}
