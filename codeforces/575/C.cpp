#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

void solve() {
  int n;
  cin >> n;
  ll l = -100000, r = 100000, u = -100000, d = 100000;
  for (int i = 0; i < n; i++) {
    ll x, y, l_ok, d_ok, r_ok, u_ok;
    cin >> x >> y >> l_ok >> d_ok >> r_ok >> u_ok;
    if (!l_ok) l = max(l, x);
    if (!r_ok) r = min(r, x);
    if (!u_ok) u = max(u, y);
    if (!d_ok) d = min(d, y);
  }
  if (l > r || u > d) cout << 0 << endl;
  else cout << "1 " << l << " " << u << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
