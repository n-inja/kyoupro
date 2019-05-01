#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int dp[5010][5010] = {0};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < t.size(); j++) {
      dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  cout << dp[s.size()][t.size()] + 1 << endl;
  return 0;
}
