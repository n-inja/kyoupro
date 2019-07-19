#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int a, b, c;
};

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

ll dp[41][401][401] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<N> ns(n);
  for (int i = 0; i < n; i++) cin >> ns[i].a >> ns[i].b >> ns[i].c;
  ll INF = 1LL << 50;
  for (int i = 0; i <= n; i++) for (int j = 0; j < 401; j++) for (int k = 0; k < 401; k++) dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 401; j++) {
      for (int k = 0; k < 401; k++) {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if (j + ns[i].a < 401 && k + ns[i].b < 401) {
          dp[i + 1][j + ns[i].a][k + ns[i].b] = min(dp[i + 1][j + ns[i].a][k + ns[i].b], dp[i][j][k] + ns[i].c);
        }
      }
    }
  }
  ll ans = INF;
  for (int i = 0; i < 401; i++)
    for (int j = 0; j < 401; j++) {
      if (i == 0 && j == 0) continue;
      if (i * mb == j * ma) {
        ans = min(ans, dp[n][i][j]);
      }
    }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
