#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 2019;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll l, r;
  cin >> l >> r;
  if (r - l > 2019) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 2019 * 2019;
  for (ll i = l; i < r; i++) {
    for (ll j = i + 1; j <= r; j++)
      ans = min(ans, (i % P * j % P) % P);
  }
  cout << ans << endl;
  return 0;
}
