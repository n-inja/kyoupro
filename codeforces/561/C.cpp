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
  vll a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) a[i] *= 2;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      auto r = upper_bound(a.begin() + i + 1, a.end(), -2 * a[i]);
      auto l = lower_bound(a.begin() + i + 1, a.end(), -a[i] / 2);
      ans += r - l;
      auto r2 = upper_bound(a.begin() + i + 1, a.end(), a[i] / 2);
      auto l2 = upper_bound(a.begin() + i + 1, a.end(), a[i]);
      ans += r2 - l2;
    } else {
      auto r = upper_bound(a.begin() + i + 1, a.end(), a[i] * 2);
      auto l = upper_bound(a.begin() + i + 1, a.end(), a[i]);
      ans += r - l;
    }
  }
  cout << ans << endl;
  return 0;
}
