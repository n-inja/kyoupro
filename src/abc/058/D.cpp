#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<bitset<5001>> dp(5050);

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  a.resize(lower_bound(a.begin(), a.end(), k) - a.begin());

  n = a.size();
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  auto f = [&](int i) {
    dp[0][0] = true;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        dp[j + 1] = dp[j];
      } else {
        dp[j + 1] = dp[j] | (dp[j] << a[j]);
      }
    }

    bool ok = false;
    for (int j = k - a[i]; j < k; j++) if (dp[n][j]) ok = true;
    return ok;
  };
  ll l = 0, r = n;
  if (f(l)) {
    cout << 0 << endl;
    return 0;
  }
  while (r - l > 1) {
    ll m = (r + l) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;

  return 0;
}
