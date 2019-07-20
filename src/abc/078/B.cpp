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
  ll x, y, z;
  cin >> x >> y >> z;
  ll l = 0, r = 10010101010;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (m * y + (m + 1) * z <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
