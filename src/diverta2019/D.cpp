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
  ll n;
  cin >> n;
  ll ans = 0;
  set<ll> s;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  for (auto &a : s) {
    ll m = n / a - 1;
    if (m <= 0) continue;
    if (n % m == n / m)
      ans += m;
  }
  cout << ans << endl;
  return 0;
}
