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

struct A {
  int y1, x1, y2, x2;
};

int main() {
  int h, w;
  cin >> h >> w;
  long long a[505][505] = {0};
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  vector<A> ans;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (a[i][j] % 2 == 1) {
        ans.push_back(A{(i + 1), (j + 1), (i + 1), (j + 2)});
        a[i][j + 1] += 1;
      }
    }
    if (i < h - 1) {
      if (a[i][w - 1] % 2 == 1) {
        ans.push_back(A{(i + 1), w, (i + 2), w});
        a[i + 1][w - 1] += 1;
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].y1 << " " << ans[i].x1 << " " << ans[i].y2 << " "
         << ans[i].x2 << endl;
  return 0;
}
