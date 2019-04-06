#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, h;
  cin >> n >> h;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  ll ans = 0;
  for (ll k = 1; k <= n; k++) {
    sort(v.begin(), v.begin() + k);
    ll hei = 0;
    for (int i = 0; i < k; i++) {
      if (i + 1 < k) {
        hei += max(v[i], v[i + 1]);
        i++;
      } else
        hei += v[i];
    }
    if (hei <= h)
      ans = max(ans, k);
    reverse(v.begin(), v.begin() + k);
    hei = 0;
    for (int i = 0; i < k; i++) {
      if (i + 1 < k) {
        hei += max(v[i + 1], v[i]);
        i++;
      } else
        hei += v[i];
    }
    if (hei <= h)
      ans = max(ans, k);
  }
  cout << ans << endl;
  return 0;
}
