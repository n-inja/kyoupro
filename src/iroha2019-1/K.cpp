#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;
ll dp[202020] = {0};
ll prod[202020] = {0};
ll keta(ll a) {
  int ret = 0;
  while (a) {
    a /= 10;
    ret++;
  }
  return ret;
}
ll power(ll e, ll x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return power((e * e) % P, x / 2);
  return (e * power(e, x - 1)) % P;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vvl v(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    v[i].resize(m);
    for (int j = 0; j < m; j++)
      cin >> v[i][j];
  }
  reverse(v.begin(), v.end());
  prod[0] = 1;
  for (int i = 0; i < n; i++) {
    prod[i + 1] = prod[i] * v[n - i - 1].size();
    prod[i + 1] %= P;
  }
  reverse(prod, prod + n);

  dp[0] = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (auto &a : v[i]) {
      sum += a;
      sum %= P;
      dp[i + 1] += (power(10, keta(a)) * dp[i]) % P;
      dp[i + 1] %= P;
    }
    ans += (((dp[i] * sum) % P) * prod[i]) % P;
    ans %= P;
  }
  cout << ans << endl;

  return 0;
}