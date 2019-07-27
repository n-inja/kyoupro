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
  vector<ll> a(n + 1), b(n);
  for (int i = 0; i < n + 1; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min(a[i], b[i]);
    b[i] -= min(a[i], b[i]);
    ans += min(a[i + 1], b[i]);
    a[i + 1] -= min(a[i + 1], b[i]);
  }
  cout << ans << endl;

  return 0;
}
