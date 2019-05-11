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
  ll r, g, b, n;
  cin >> r >> g >> b >> n;
  ll ans = 0;
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= n; j++) {
      ll rest = n - i * r - j * g;
      if (rest < 0) continue;
      if (rest % b) continue;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
