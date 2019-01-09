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

struct N {
  int w, s, v;
};
bool operator<(const N &l, const N &r) {
  if (l.w + l.s == r.w + r.s)
    return l.s < r.s;
  return l.w + l.s < r.w + r.s;
}

long long dp[1010][20101] = {0};
int main() {
  int n;
  cin >> n;
  vector<N> ns(n);
  for (int i = 0; i < n; i++)
    cin >> ns[i].w >> ns[i].s >> ns[i].v;
  sort(ns.begin(), ns.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20201; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j >= ns[i].w && j - ns[i].w <= ns[i].s)
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - ns[i].w] + ns[i].v);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 20201; i++)
    ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
