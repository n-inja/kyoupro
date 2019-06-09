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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> l(n + 1), r(n + 1);
  for (int i = 0; i < n; i++) r[i + 1] = r[i] + a[i];
  for (int i = 0; i < n; i++) l[i + 1] = l[i] + a[n - 1 - i];
  ll ans = 1000000000000000LL;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, abs(r[i] - l[n - i]));
  }
  cout << ans << endl;
  return 0;
}
