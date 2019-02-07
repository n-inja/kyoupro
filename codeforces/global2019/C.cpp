#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++) {
    int k = 0, j = 0;
    ll m = v[i];
    while (v[i]) {
      if (v[i] & 1LL)
        j++;
      k++;
      v[i] >>= 1;
    }
    if (j == k) {
      ll ans = 1;
      for (ll l = 2; l * l <= m; l++) {
        if (m % l == 0)
          ans = max(ans, max(gcd(m - l, l), gcd(m - m / l, m / l)));
      }
      cout << ans << endl;
    } else {
      cout << (1LL << k) - 1 << endl;
    }
  }
  return 0;
}
