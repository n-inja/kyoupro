#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll P = 1000000007;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vll c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  vll sum(202020);
  vll dp(202020);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = dp[i];
    ll tmp = dp[i + 1];
    if (i < n && c[i + 1] == c[i])
      continue;
    dp[i + 1] += sum[c[i]];
    dp[i + 1] %= P;
    sum[c[i]] += tmp;
    sum[c[i]] %= P;
  }
  cout << dp[n] << endl;
  return 0;
}
