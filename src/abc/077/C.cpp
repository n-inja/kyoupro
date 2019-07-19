#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    auto ar = lower_bound(a.begin(), a.end(), b[i]);
    auto cl = upper_bound(c.begin(), c.end(), b[i]);
    ans += (ll) (ar - a.begin()) * (c.end() - cl);
  }
  cout << ans << endl;
  return 0;
}
