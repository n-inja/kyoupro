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

int offset = 1000;
int n, m;
string s[1000];

void solve() {
  cin >> n >> m;
  vector<vector<int>> rot;
  rot.resize(2000);
  for (int i = 0; i < 2000; i++)
    rot[i].resize(2000);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      rot[i + j][i - j + offset] = s[i][j] - '0';
    }
  }
  vector<vector<int>> sumx(2001);
  vector<vector<int>> sumy(2001);
  for (int i = 0; i < 2001; i++) {
    sumx[i].resize(2001);
    sumy[i].resize(2001);
  }
  for (int i = 0; i < 2000; i++) {
    for (int j = 0; j < 2000; j++) {
      sumx[i][j + 1] = sumx[i][j] + rot[i][j];
    }
    for (int j = 0; j < 2000; j++) {
      sumy[i + 1][j] = sumy[i][j] + rot[i][j];
    }
  }
  vector<int> ansv;
  for (int d = 1; d <= n + m - 2; d++) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int ry = i + j, rx = i - j + offset;
        if (rot[ry][rx]) {
          if (ry - d >= 0)
            ans += sumx[ry - d][min(rx + d + 1, 2000)] -
                   sumx[ry - d][max(rx - d, 0)];
          if (ry + d < 2000)
            ans += sumx[ry + d][min(rx + d + 1, 2000)] -
                   sumx[ry + d][max(rx - d, 0)];
          if (rx - d >= 0)
            ans += sumy[min(ry + d, 2000)][rx - d] -
                   sumy[max(ry - (d - 1), 0)][rx - d];
          if (rx + d < 2000)
            ans += sumy[min(ry + d, 2000)][rx + d] -
                   sumy[max(ry - (d - 1), 0)][rx + d];
        }
      }
    }
    ansv.push_back(ans / 2);
  }
  cout << ansv[0];
  for (int i = 1; i < ansv.size(); i++)
    cout << " " << ansv[i];
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    solve();
  }
  return 0;
}
