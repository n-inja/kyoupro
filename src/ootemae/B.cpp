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
  ll n, m, k;
  cin >> m >> n >> k;
  vector<ll> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    set<ll> s;
    ll base = 0;
    for (int j = 0; j < n; j++) {
      if (x[j] == i) {
        base++;
        continue;
      }
      if (abs(x[j] - i) <= k) {
        s.insert(abs(x[j] - i));
      }
    }
    ans = max(ans, base + (ll) s.size());
  }
  cout << ans << endl;
  return 0;
}
