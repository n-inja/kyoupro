#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

long long P = 1000000007;

ll dp[404][404] = {0};
ll memo[404][404] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)cin >> a[i];
  for (int i = 0; i < n; i++)cin >> b[i];

  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j <= b[i]; j++) {
      ll tmp = 1;
      for (int k = 0; k <= c; k++) {
        memo[i][k] += tmp;
        memo[i][k] %= P;
        tmp *= j;
        tmp %= P;
      }
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= c; j++) {
      dp[i + 1][j] = 0;
      for (int k = 0; k <= c; k++) {
        if (j - k < 0) continue;
        dp[i + 1][j] += (dp[i][j - k] * memo[i][k]) % P;
        dp[i + 1][j] %= P;
      }
    }
  }
  cout << dp[n][c] << endl;
  return 0;
}
