#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll gcd(ll a, ll b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vll l(n + 1), r(n + 1);
  l[0] = 0;
  for (int i = 1; i <= n; i++) {
    l[i] = gcd(l[i - 1], v[i - 1]);
  }
  r[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    r[i] = gcd(r[i + 1], v[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, gcd(l[i], r[i + 1]));
  }
  cout << ans << endl;
  return 0;
}
