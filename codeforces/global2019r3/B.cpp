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
  ll n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  ll ealr = a[0] + ta;
  ll bi = -1;
  ll late = b[m - 1] - ta;
  ll ai = n;

  for (int i = 0; i < n; i++) {
    if (a[i] > late) {
      ai = i;
      break;
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    if (b[i] < ealr) {
      bi = i;
      break;
    }
  }
  /*
  if (ai - n < k || m - bi + 1 < k) {
    cout << -1 << endl;
    return 0;
  }
  */

  ll ans = -1;
  for (int i = 0; i <= k; i++) {
    int j = k - i;
    if (i >= n) {
      cout << -1 << endl;
      return 0;
    }
    ll t = a[i] + ta;
    auto it = lower_bound(b.begin(), b.end(), t);
    if (b.end() - it < j) {
      cout << -1 << endl;
      return 0;
    }
    it += j;
    ans = max(ans, *it + tb);
  }
  cout << ans << endl;

  return 0;
}
