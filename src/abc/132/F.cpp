#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;
ll dp[100][101010] = {0};
ll sdp[100][101010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;

  vector<ll> p;

  p.push_back(0);
  for (ll i = 1; i <= n; i++) {
    ll r = n / i;
    if (n / r != i) p.push_back(i);
    i = n / r;
    p.push_back(i);
  }

  // (p[0], p[1]], (p[1], p[2]], ..

  for (int i = 1; i < p.size(); i++) {
    dp[0][i - 1] = (p[i] - p[i - 1] + P) % P;
  }
  ll m = p.size();

  sdp[0][0] = 0;
  for (int i = 1; i <= m; i++) sdp[0][i] = (sdp[0][i - 1] + dp[0][i - 1]) % P;

  for (int i = 0; i < k - 1; i++) {
    for (int j = 1; j < m; j++) {
      // p[j - 1], p[j]
      ll id = upper_bound(p.begin(), p.end(), n / p[j]) - p.begin();
      id--;
      dp[i + 1][j - 1] = (dp[0][j - 1] * sdp[i][id]) % P;
    }
    sdp[i + 1][0] = 0;
    for (int j = 1; j <= m; j++) sdp[i + 1][j] = (sdp[i + 1][j - 1] + dp[i + 1][j - 1]) % P;
  }

  cout << sdp[k - 1][m] << endl;

  return 0;
}
