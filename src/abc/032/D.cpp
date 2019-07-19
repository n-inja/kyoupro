#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll n, w;
vector<pair<ll, ll>> ps;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> w;
  ps.resize(n);
  for (int i = 0; i < n; i++) cin >> ps[i].first >> ps[i].second;
  ll INF = 1LL << 62;
  ll allw = ps[0].second;
  for (int i = 0; i < n; i++) allw = max(allw, ps[i].second);
  if (n <= 20) {
    int bit = 1 << n;
    ll ans = 0;
    for (int i = 0; i < bit; i++) {
      ll weight = 0;
      ll value = 0;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          weight += ps[j].second;
          value += ps[j].first;
        }
      }
      if (weight <= w) ans = max(ans, value);
    }
    cout << ans << endl;
  } else if (n <= 30) {
    int bit2 = 1 << (n - 20);
    map<ll, ll> mp;
    int m = n - 20;
    for (int i = 0; i < bit2; i++) {
      ll weight = 0;
      ll value = 0;
      for (int j = 0; j < m; j++) {
        if ((i >> j) & 1) {
          weight += ps[j + 20].second;
          value += ps[j + 20].first;
        }
      }
      mp[weight] = max(mp[weight], value);
    }
    mp[0] = 0;
    ll maxvalue = 0;
    vector<ll> wfirst;
    for (auto &v : mp) {
      maxvalue = max(maxvalue, v.second);
      v.second = maxvalue;
      wfirst.push_back(v.first);
    }

    int bit = 1 << 20;
    ll ans = 0;
    for (int i = 0; i < bit; i++) {
      ll weight = 0;
      ll value = 0;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          weight += ps[j].second;
          value += ps[j].first;
        }
      }
      if (weight <= w) {
        ll rest = w - weight;

        auto it = upper_bound(wfirst.begin(), wfirst.end(), rest);
        it--;
        ans = max(ans, value + mp[*it]);
      }
    }
    cout << ans << endl;
  } else if (allw <= 1000) {
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= w; j++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if (j < w)
          dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        if (j + ps[i].second <= w) {
          dp[i + 1][j + ps[i].second] = max(dp[i + 1][j + ps[i].second], dp[i][j] + ps[i].first);
        }
      }
    }
    cout << dp[n][w] << endl;
  } else {
    ll val = 200001;
    vector<vector<ll>> dp(n + 1, vector<ll>(val, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < val; j++) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        if (j + ps[i].first < val) {
          dp[i + 1][j + ps[i].first] = min(dp[i + 1][j + ps[i].first], dp[i][j] + ps[i].second);
        }
      }
    }
    ll ans = 0;
    for (int i = 0; i < val; i++) {
      if (dp[n][i] > w) continue;
      ans = i;
    }
    cout << ans << endl;
  }

  return 0;
}
