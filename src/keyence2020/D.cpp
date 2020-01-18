#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[1 << 20][36] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> ps(n);
  for (int i = 0; i < n; i++) cin >> ps[i].first;
  for (int i = 0; i < n; i++) cin >> ps[i].second;
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    ps[i].first--;
    ps[i].second--;
    mp[ps[i].first] = mp[ps[i].second] = 0;
  }
  ll cc = 0;
  for (auto &it : mp) it.second = cc++;
  for (int i = 0; i < n; i++) {
    ps[i].first = mp[ps[i].first];
    ps[i].second = mp[ps[i].second];
  }
  ll bit = 1 << n;
  ll INF = 1LL << 50;
  for (int i = 0; i < bit; i++) for (int j = 0; j < 50; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 0; i < bit; i++) {
    int setted = 0;
    for (int j = 0; j < n; j++) if (i & (1LL << j)) setted++;
    for (int j = 0; j < 36; j++) {
      if (dp[i][j] >= INF) continue;
      int c = 0;
      // k - setted + c -> setted
      for (int k = 0; k < n; k++) {
        ll b = 1LL << k;
        if (i & b) {
          c++;
          continue;
        }
        ll d = k - c;
        ll v = ps[k].first;
        if (abs(setted - k) % 2) {
          v = ps[k].second;
        }
        if (v < j) continue;
        dp[i | b][v] = min(dp[i | b][v], dp[i][j] + d);
      }
    }
  }

  ll ans = INF;
  for (int i = 0; i < 36; i++) {
    ans = min(ans, dp[bit - 1][i]);
  }
  if (ans < INF) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}
