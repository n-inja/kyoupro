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
  ll a, b, c;
  cin >> a >> b >> c;
  ll g = __gcd(a, b);
  ll lcm = a * b / g;
  ll i = lcm;
  while (i < c) i += lcm;
  cout << i << endl;

  return 0;
}
