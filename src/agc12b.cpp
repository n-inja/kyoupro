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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> p(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  pair<int, int> dp[101010][11];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 11; j++)
      dp[i][j] = make_pair(0, 0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, d, c;
    cin >> v >> d >> c;
    v--;
    dp[v][d] = make_pair(i + 1, c);
  }
  for (int d = 9; d >= 0; d--) {
    for (int i = 0; i < n; i++) {
      if (dp[i][d].first < dp[i][d + 1].first) {
        dp[i][d] = dp[i][d + 1];
      }
      for (int j = 0; j < p[i].size(); j++) {
        if (dp[i][d].first < dp[p[i][j]][d + 1].first) {
          dp[i][d] = dp[p[i][j]][d + 1];
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << dp[i][0].second << endl;
  return 0;
}
