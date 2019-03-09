#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  b++;
  ll ans = 0;
  for (int k = 0; k < 50; k++) {
    ll ca = (a >> (k + 1)) * (1LL << k) +
            max(0LL, a % ((1LL << (k + 1))) - (1LL << k));
    ll cb = (b >> (k + 1)) * (1LL << k) +
            max(0LL, b % ((1LL << (k + 1))) - (1LL << k));
    if ((cb - ca) % 2 == 1) {
      ans += (1LL << k);
    }
  }
  cout << ans << endl;
  return 0;
}
