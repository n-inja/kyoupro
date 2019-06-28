#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[101010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, a;
  cin >> n >> m >> a;

  vector<vector<pair<ll, ll>>> ps(n + 1);
  for (int i = 0; i < m; i++) {
    ll l, r, c;
    cin >> l >> r >> c;
    ps[r].emplace_back(l - 1, c);
  }
  dp[0] = 0;
  ll summax = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = summax - (i == n ? 0 : a);
    for (auto &v : ps[i]) {
      dp[i] = max(dp[i], dp[v.first] + v.second - (i == n ? 0 : a));
    }
    summax = max(summax, dp[i]);
  }
  cout << summax << endl;

  return 0;
}
