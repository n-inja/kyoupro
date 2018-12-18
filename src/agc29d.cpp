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
  int n, h, w;
  cin >> h >> w >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end(),
       [](const pair<int, int> &l, const pair<int, int> &r) {
         if (l.second == r.second) {
           return l.first < r.first;
         }
         return l.second < r.second;
       });
  int ans = h;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second + c < p[i].first)
      ans = min(ans, p[i].first - 1);
    else if (p[i].second + c == p[i].first)
      c++;
  }
  cout << ans << endl;
  return 0;
}
