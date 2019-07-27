#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;
ll dp[101010][13] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  int po10[101010] = {0};
  po10[0] = 1;
  for (int i = 0; i <= n; i++) po10[i + 1] = (po10[i] * 10) % 13;

  reverse(s.begin(), s.end());
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 13; j++) {
      if (s[i] == '?') {
        for (int k = 0; k < 10; k++) {
          dp[i + 1][(j + k * po10[i]) % 13] += dp[i][j];
          dp[i + 1][(j + k * po10[i]) % 13] %= P;
        }
      } else {
        dp[i + 1][(j + (s[i] - '0') * po10[i]) % 13] += dp[i][j];
        dp[i + 1][(j + (s[i] - '0') * po10[i]) % 13] %= P;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}
