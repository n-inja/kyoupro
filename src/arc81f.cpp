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

using pil = pair<int, long long>;
using pll = pair<long long, long long>;

long long largestRectangleFromHist(vector<pll> &v) {
  v.push_back(make_pair(0, 0));
  int n = v.size();
  long long ans = 0;
  vector<pil> stack;
  for (int i = 0; i < n; i++) {
    if (stack.size() == 0) {
      stack.push_back(make_pair(i, v[i].second));
      ans = max(ans, v[i].first);
    } else {
      if (stack[stack.size() - 1].second <= v[i].second) {
        ans = max(ans, v[i].first);
        stack.push_back(make_pair(i, v[i].second));
      } else if (v[i].second < stack[stack.size() - 1].second &&
                 stack[stack.size() - 1].second <= v[i].first) {
        int j = i;
        while (stack.size() > 0 &&
               stack[stack.size() - 1].second > v[i].second) {
          j = min(j, stack[stack.size() - 1].first);
          ans = max(ans, (i - stack[stack.size() - 1].first + 1) *
                             stack[stack.size() - 1].second);
          stack.pop_back();
        }
        stack.push_back(make_pair(j, v[i].second));
      } else {
        int j = i;
        while (stack.size() > 0 &&
               stack[stack.size() - 1].second > v[i].second) {
          j = min(j, stack[stack.size() - 1].first);
          ans = max(ans, (i - stack[stack.size() - 1].first) *
                             stack[stack.size() - 1].second);
          stack.pop_back();
        }
        stack.push_back(make_pair(j, v[i].second));
      }
    }
  }
  return ans;
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> mp(h);
  for (int i = 0; i < h; i++)
    cin >> mp[i];

  bool ng[2005][2005] = {0}, ng2[2005][2005] = {0};
  for (int i = 0; i < h - 1; i++)
    for (int j = 0; j < w - 1; j++) {
      int sum = 0;
      if (mp[i][j] == '#')
        sum++;
      if (mp[i + 1][j] == '#')
        sum++;
      if (mp[i][j + 1] == '#')
        sum++;
      if (mp[i + 1][j + 1] == '#')
        sum++;
      if (sum % 2 == 1)
        ng[i + 1][j + 1] = ng2[i + 1][j + 1] = true;
    }
  vector<vector<int>> table(h), table2;
  for (int i = 0; i < h; i++) {
    table[i].resize(w);
    for (int j = 0; j < w; j++)
      table[i][j] = 1;
  }
  table2 = table;
  for (int i = 1; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (!(ng[i][j] && ng[i][j + 1]) && !ng[i][j + 1]) {
        table[i][j] = table[i - 1][j] + 1;
      }
      if (!(ng2[i][j] && ng2[i][j + 1])) {
        table2[i][j] = table2[i - 1][j] + 1;
      }
    }
  long long ans = 0;
  for (int i = 0; i < h; i++) {
    vector<pll> v;
    for (int j = 0; j < w; j++) {
      v.push_back(make_pair(table2[i][j], table[i][j]));
    }
    ans = max(ans, largestRectangleFromHist(v));
  }
  cout << ans << endl;
  return 0;
}
