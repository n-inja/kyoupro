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
  int n, k;
  cin >> n >> k;
  vector<ll> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  ll ans = 0;
  for (auto &x1 : x)
    for (auto &x2 : x)
      for (auto &y1 : y)
        for (auto &y2 : y) {
          if (x1 == x2 || y1 == y2) continue;
          int c = 0;
          ll l = min(x1, x2);
          ll r = max(x1, x2);
          ll u = min(y1, y2);
          ll d = max(y1, y2);
          for (int i = 0; i < n; i++) if (l <= x[i] && x[i] <= r && u <= y[i] && y[i] <= d) c++;
          if (c >= k) {
            if (ans == 0) ans = (r - l) * (d - u);
            ans = min(ans, (r - l) * (d - u));
          }
        }
  cout << ans << endl;
  return 0;
}
