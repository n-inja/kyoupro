#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll P = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
      cout << 0 << endl;
      continue;
    }
    ll ans = 0;
    // A B 縦

    ll na = n - a + 1;
    ll nb = n - b + 1;
    ll c = n - a - b + 1;
    ll s = (na * nb) % P;
    ll t = (P + (c * c) % P - ((c * (c - 1) % P) * 500000004) % P) % P;
    ll ans1 = (s * t) % P;

    // A B naname
    ll ans2 = (c * c) % P;
    ans2 *= (c + 1) * (c + 1) % P;
    ans2 %= P;
    ans2 *= 500000004;
    ans2 %= P;
    ans2 *= 500000004;
    ans2 %= P;

    ll ans3 = (2 * P + ans1 - ans2 * 2) % P;
    ans = (ans2 + ans3) * 4;
    ans %= P;

    cout << ans << endl;
  }
  return 0;
}
