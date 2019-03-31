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

vector<vector<long long>> dp(500001);
long long solve(vector<int> &v) {
  if (v.size() < 2)
    return 0;
  dp[0][0] = dp[1][0] = dp[0][1] = dp[1][1] = dp[0][2] = dp[1][2] = dp[0][3] =
      dp[1][3] = 0;
  for (int i = 1; i < v.size(); i++) {
    dp[i + 1][0] = max(max(dp[i][0], dp[i][1]), max(dp[i][2], dp[i][3]));
    if (v[i - 1] > 1) {
      // right
      dp[i + 1][2] =
          max(max(dp[i][0] + v[i], dp[i][1] + v[i]), dp[i][3] + v[i]);
      // left
      dp[i + 1][1] = max(dp[i][0] + v[i - 1], dp[i][1] + v[i - 1] - 1);
      if (v[i] > 1) {
        dp[i + 1][3] =
            max(max(dp[i][0] + v[i], dp[i][1] + v[i]), dp[i][3] + v[i]) - 1;
      } else {
        dp[i + 1][3] = 0;
      }
    } else {
      dp[i + 1][2] = dp[i][0] + v[i];
      dp[i + 1][1] = dp[i][0] + v[i - 1];
      if (v[i] > 1) {
        dp[i + 1][3] = dp[i][0] + v[i] - 1;
      } else {
        dp[i + 1][3] = 0;
      }
    }
  }
  return max(max(dp[v.size()][0], dp[v.size()][1]),
             max(dp[v.size()][2], dp[v.size()][3]));
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i <= n; i++)
    dp[i].resize(4);
  s.push_back('0');
  vector<pair<int, int>> v;
  int now = '0', c = 1;
  for (int i = 0; i < n + 1; i++) {
    if (s[i] == now) {
      c++;
    } else {
      v.push_back(make_pair(now, c));
      c = 1;
    }
    now = s[i];
  }
  vector<vector<int>> q;
  vector<int> w;
  for (int i = 1; i < v.size(); i += 2) {
    if (v[i - 1].second == 1) {
      w.push_back(v[i].second);
    } else {
      if (w.size() > 0)
        q.push_back(w);
      w.clear();
      w.push_back(v[i].second);
    }
  }
  if (w.size() > 0)
    q.push_back(w);
  long long ans = 0;
  for (int i = 0; i < q.size(); i++) {
    ans += solve(q[i]);
  }
  cout << ans << endl;
  return 0;
}
