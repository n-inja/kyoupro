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
  int k;
  cin >> k;
  int n = 500;
  vector<vector<int>> mp(n);
  for (int i = 0; i < n; i++)
    mp[i].resize(n);
  if (k <= 500) {
    cout << k << endl;
    for (int i = 0; i < k; i++) {
      cout << i + 1;
      for (int j = 1; j < k; j++)
        cout << " " << i + 1;
      cout << endl;
    }
  } else {
    int c = 1;
    for (int i = 0; i < n; i++) {
      bool d = k - 500 > i;
      for (int j = 0; j < n; j++) {
        if (d)
          mp[(i + j) % n][j] = c + j % 2;
        else
          mp[(i + j) % n][j] = c;
      }
      if (d)
        c++;
      c++;
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << mp[i][0];
      for (int j = 1; j < n; j++)
        cout << " " << mp[i][j];
      cout << endl;
    }
  }
  return 0;
}
