#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 998244353;
ll pw(ll a, ll b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  if (b % 2 == 0)
    return pw((a * a) % P, b / 2);
  return (pw(a, b - 1) * a) % P;
}
ll dp[301][90001] = {0};
ll dp2[301][90001] = {0};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vll a(n), s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }
  dp[0][0] = 1;
  // dp[i][j] := iまでで B+Gがjであるような色の塗り方
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 90000; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= P;
      if (j + a[i] <= 90000) {
        dp[i + 1][j + a[i]] += dp[i][j] * 2;
        dp[i + 1][j + a[i]] %= P;
      }
    }
  }
  dp2[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 90000; j++) {
      dp2[i + 1][j] += dp2[i][j];
      dp2[i + 1][j] %= P;
      if (j + a[i] <= 90000) {
        dp2[i + 1][j + a[i]] += dp2[i][j];
        dp2[i + 1][j + a[i]] %= P;
      }
    }
  }

  ll no = 0;
  for (ll i = 0; i <= s[n]; i++) {
    ll R = s[n] - i;
    if (R >= (s[n] + 1) / 2) {
      no += dp[n][i];
      no %= P;
    }
  }
  ll same = 0;
  if (s[n] % 2 == 0)
    same = dp2[n][s[n] / 2];
  ll ans = pw(3, n);
  ans += P * 3 - no * 3;
  ans %= P;
  ans += same * 3;
  ans %= P;

  cout << ans << endl;

  return 0;
}
