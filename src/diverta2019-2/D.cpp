#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll n;
ll g[3], b[3];
vector<pair<ll, ll>> p, m;

ll f(vector<pair<ll, ll>> p, ll n) {
  ll ans = n;
  if (p.size() == 3) {
    for (ll i = 0; i <= 5000; i++) {
      for (ll j = 0; j <= 5000; j++) {
        if (n < p[0].first * i + p[1].first * j) continue;
        ll m = n - p[0].first * i - p[1].first * j;
        int k = m / p[2].first;
        m -= p[2].first * k;
        ans = max(ans, m + p[0].second * i + p[1].second * j + p[2].second * k);
      }
    }
  } else if (p.size() == 2) {
    for (ll i = 0; i * p[0].first <= n; i++) {
      ll m = n - p[0].first * i;
      ll j = m / p[1].first;
      m -= j * p[1].first;
      ans = max(ans, m + i * p[0].second + j * p[1].second);
    }
  } else if (p.size() == 1) {
    ll i = n / p[0].first;
    n -= p[0].first * i;
    ans = max(ans, n + i * p[0].second);
  }
  return ans;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> g[0] >> g[1] >> g[2] >> b[0] >> b[1] >> b[2];
  ll ans = n;

  for (int i = 0; i < 3; i++) {
    if (g[i] < b[i]) p.emplace_back(g[i], b[i]);
    else if (g[i] > b[i]) m.emplace_back(b[i], g[i]);
  }
  ans = f(p, n);
  ans = f(m, ans);

  cout << ans << endl;
  return 0;
}
