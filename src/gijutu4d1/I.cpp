#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[4][202020] = {0};
ll sdp[4][202020] = {0};
ll P = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = 0; i < m; i++) dp[3][i] = 1;
  for (int i = 0; i < m; i++) sdp[3][i + 1] = sdp[3][i] + dp[3][i];

  for (int i = 0; i < n; i++) {
    int j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    dp[2][i] = (sdp[3][m] - sdp[3][j] + P) % P;
  }
  for (int i = 0; i < n; i++) sdp[2][i + 1] = (sdp[2][i] + dp[2][i]) % P;

  for (int i = 0; i < n; i++) {
    int j = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
    dp[1][i] = (sdp[2][n] - sdp[2][j] + P) % P;
  }
  for (int i = 0; i < n; i++) sdp[1][i + 1] = (sdp[1][i] + dp[1][i]) % P;

  for (int i = 0; i < m; i++) {
    int j = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
    dp[0][i] = (sdp[1][n] - sdp[1][j] + P) % P;
  }
  for (int i = 0; i < m; i++) sdp[0][i + 1] = (sdp[0][i] + dp[0][i]) % P;
  cout << sdp[0][m] << endl;

  return 0;
}
