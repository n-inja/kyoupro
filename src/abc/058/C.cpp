#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll x;

bool f(ll m) {
  ll y = x;
  for (int i = m; i > 0; i--) {
    if ((y -= i) <= 0) return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll l = 0, r = 1000000;
  cin >> x;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;
  return 0;
}
