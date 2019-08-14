#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[101010][3] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<char> op(n);
  ll INF = 1LL << 50;
  op[0] = '+';
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i < n - 1)
      cin >> op[i + 1];
  }
  for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = dp[i][2] = -INF;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    if (op[i] == '+') {
      dp[i + 1][0] = max(a[i] + dp[i][0], max(a[i] + dp[i][1], a[i] + dp[i][2]));
      dp[i + 1][1] = max(-a[i] + dp[i][1], -a[i] + dp[i][2]);
      dp[i + 1][2] = a[i] + dp[i][2];
    } else {
      dp[i + 1][0] = max(-a[i] + dp[i][0], max(-a[i] + dp[i][1], -a[i] + dp[i][2]));
      dp[i + 1][1] = max(-a[i] + dp[i][0], max(a[i] + dp[i][1], a[i] + dp[i][2]));
      dp[i + 1][2] = max(a[i] + dp[i][1], a[i] + dp[i][2]);
    }
  }

  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
  return 0;
}
