#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[1 << 13] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ps(m);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> ps[i].first >> t;
    for (int j = 0; j < t; j++) {
      int k;
      cin >> k;
      k--;
      ps[i].second = ps[i].second | (1 << k);
    }
  }
  ll INF = 1LL << 40;
  for (int i = 0; i < (1 << n); i++) dp[i] = INF;
  dp[0] = 0;

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < m; j++) {
      dp[i | ps[j].second] = min(dp[i | ps[j].second], dp[i] + ps[j].first);
    }
  }

  if (dp[(1 << n) - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << dp[(1 << n) - 1] << endl;
  }
  return 0;
}
