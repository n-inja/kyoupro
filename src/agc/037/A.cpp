#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[202020][3] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  string t = "^ " + s;
  for (int i = 0; i < n; i++) {
    if (t[i + 2] != t[i + 1]) {
      dp[i + 1][0] = dp[i][0] + 1;
    }
    if (i > 1 && (t[i + 2] != t[i] || t[i + 1] != t[i - 1])) {
      dp[i + 1][1] = dp[i - 1][1] + 1;
    }
    dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 1);
    if (i > 0) {
      dp[i + 1][1] = max(dp[i + 1][1], dp[i - 1][0] + 1);
    }
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}
