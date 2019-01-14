#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll P = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  ll ans = 1;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<bool> aused(n), bused(m);
  for (int i = 0; i < n - 1; i++)
    if (a[i + 1] == a[i]) {
      cout << 0 << endl;
      return 0;
    }
  for (int i = 0; i < m - 1; i++)
    if (b[i + 1] == b[i]) {
      cout << 0 << endl;
      return 0;
    }
  map<ll, bool> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (a[i] == b[j]) {
        mp[a[i]] = true;
        aused[i] = true;
        bused[j] = true;
      }
  }
  vi asum(n + 1), bsum(m + 1);
  for (int i = 0; i < n; i++) {
    asum[i + 1] = asum[i] + aused[i];
  }
  for (int i = 0; i < m; i++) {
    bsum[i + 1] = bsum[i] + bused[i];
  }
  int oks = 0;
  for (int i = n * m; i > 0; i--) {
    if (mp[i]) {
      oks++;
      continue;
    }
    auto ait = lower_bound(a.begin(), a.end(), i);
    ll ac = n - (ait - a.begin());
    bool f = false;
    if (ait != a.end() && *ait == i) {
      ac = 1;
      f = true;
    }
    auto bi = lower_bound(b.begin(), b.end(), i);
    ll bc = m - (bi - b.begin());
    if (bi != b.end() && *bi == i) {
      bc = 1;
      f = true;
    }
    if (f) {
      ans *= ac * bc;
      ans %= P;
    } else {
      ans *= ac * bc - oks;
      ans %= P;
    }
    oks++;
  }

  cout << ans << endl;
  return 0;
}
