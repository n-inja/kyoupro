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
int n;
vector<string> mp;

void draw(int y, int x) {
  for (int i = 0; i < n; i++) {
    if (i <= x)
      mp[y][i] = 'o';
    if (i >= x && y + 1 < n)
      mp[y + 1][i] = 'o';
  }
}

int main() {
  cin >> n;
  mp.resize(n);
  for (int i = 0; i < n; i++)
    cin >> mp[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--)
      if (mp[i][j] == '.') {
        ans++;
        draw(i, j);
      }
  }
  cout << ans << endl;
  return 0;
}
