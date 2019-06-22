#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll f(ll a, ll b) {
  return a / b;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll g = __gcd(c, d);
  ll l = c / g * d;

  ll all = b - a + 1;
  ll cc = f(b, c) - f(a - 1, c);
  ll dc = f(b, d) - f(a - 1, d);
  ll cdc = f(b, l) - f(a - 1, l);

  cout << all - cc - dc + cdc << endl;

  return 0;
}
