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
  ll a, b;
  cin >> a >> b;
  for (ll i = 1; i < 1000000; i++) {
    ll fa = i * 8 / 100;
    ll fb = i / 10;
    if (fa == a && fb == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
