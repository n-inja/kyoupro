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
  int n, m;
  ll k, e;
  cin >> n >> m >> k >> e;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(b.rbegin(), b.rend());
  sort(a.begin(), a.end());

  auto f = [&](ll l) {
    ll g = e;
    for (int i = 0; i < l; i++) g += b[i];
    for (int i = 0; i < n; i++) {
      if (g - a[i] >= 0) g -= a[i];
      else return false;
    }
    return true;
  };
  auto h = [&]() {
    ll r = e;
    for (int i = 0; i < k; i++) r += b[i];
    for (int i = 0; i < n; i++) {
      if (r - a[i] >= 0) r -= a[i];
      else return i;
    }
    return n;
  };

  if (!f(k)) {
    cout << "No" << endl;
    cout << h() << endl;
    return 0;
  }
  if (f(0)) {
    cout << "Yes" << endl;
    cout << 0 << endl;
    return 0;
  }

  ll l = 0, r = k;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (f(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << "Yes" << endl;
  cout << r << endl;

  return 0;
}
