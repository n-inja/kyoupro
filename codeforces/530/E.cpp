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
string v = "ATGC";

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++)
    cin >> s[i];
  int minDiff = 1000000000;
  vector<string> ans;
  for (int c1 = 0; c1 < 4; c1++)
    for (int c2 = c1 + 1; c2 < 4; c2++) {
      string t;
      {
        set<int> s;
        for (int i = 0; i < 4; i++)
          s.insert(i);
        s.erase(c1);
        s.erase(c2);
        auto it = s.begin();
        t.push_back(v[c1]);
        t.push_back(v[c2]);
        t.push_back(v[*(it++)]);
        t.push_back(v[*it]);
      }

      int diff = 0;
      vector<string> tmp(h);
      for (int i = 0; i < h; i++) {
        int b = (i % 2) * 2;
        int d1 = 0, d2 = 0;
        for (int j = 0; j < w; j++) {
          if (s[i][j] != t[b + (j % 2)])
            d1++;
          if (s[i][j] != t[b + (j + 1) % 2])
            d2++;
        }
        if (d1 < d2) {
          for (int j = 0; j < w; j++)
            tmp[i].push_back(t[b + (j % 2)]);
        } else {
          for (int j = 0; j < w; j++)
            tmp[i].push_back(t[b + (j + 1) % 2]);
        }
        diff += min(d1, d2);
      }
      if (diff < minDiff) {
        ans = tmp;
        minDiff = diff;
      }
      diff = 0;
      tmp.clear();
      tmp.resize(h);
      for (int j = 0; j < w; j++) {
        int b = (j % 2) * 2;
        int d1 = 0, d2 = 0;
        for (int i = 0; i < h; i++) {
          if (s[i][j] != t[b + (i % 2)])
            d1++;
          if (s[i][j] != t[b + (i + 1) % 2])
            d2++;
        }
        if (d1 < d2) {
          for (int i = 0; i < h; i++)
            tmp[i].push_back(t[b + (i % 2)]);
        } else {
          for (int i = 0; i < h; i++)
            tmp[i].push_back(t[b + (i + 1) % 2]);
        }
        diff += min(d1, d2);
      }
      if (diff < minDiff) {
        ans = tmp;
        minDiff = diff;
      }
    }
  for (int i = 0; i < h; i++)
    cout << ans[i] << endl;
  return 0;
}
