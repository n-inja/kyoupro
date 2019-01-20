#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, l, r;
  cin >> n >> l >> r;
  ll dp[n + 1][3];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 3; j++)
      dp[i][j] = 0;
  dp[0][0] = 1;
  int a[3] = {0};
  l--;
  a[0] = r / 3 - l / 3;
  a[1] = (r + 1) / 3 - (l + 1) / 3;
  a[2] = (r + 2) / 3 - (l + 2) / 3;
  ll P = 1000000007;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i + 1][(j + k) % 3] += (dp[i][j] * a[k]) % P;
        dp[i + 1][(j + k) % 3] %= P;
      }
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}
