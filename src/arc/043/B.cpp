#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  ll P = 1000000007;
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  sort(d.begin(), d.end());
  vector<vector<ll>> dp(4, vector<ll>(n)), sdp(4, vector<ll>(n + 1));
  for (int i = 0; i < n; i++) dp[0][i] = 1;
  for (int i = 0; i < n; i++) sdp[0][i + 1] = (sdp[0][i] + dp[0][i]) % P;
  for (int i = 1; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      auto p = lower_bound(d.begin(), d.end(), d[j] * 2) - d.begin();
      dp[i][j] = (sdp[i - 1][n] - sdp[i - 1][p] + P) % P;
    }
    for (int j = 0; j < n; j++) sdp[i][j + 1] = (sdp[i][j] + dp[i][j]) % P;
  }

  cout << sdp[3][n] << endl;

  return 0;
}
