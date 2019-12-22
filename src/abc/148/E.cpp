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
  ll n;
  cin >> n;
  if (n % 2) {
    cout << 0 << endl;
    return 0;
  }
  ll d5 = 0, d2 = 0;
  ll p5 = 1, p2 = 1;
  for (ll k = 0; k < 10000; k++) {
    p5 *= 5;
    d5 += n / p5 / 2;
    if (n / p5 == 0) break;
  }
  for (ll k = 0; k < 10000; k++) {
    p2 *= 2;
    d2 += n / p2;
    if (n / p2 == 0) break;
  }
  cout << min(d2, d5) << endl;

  return 0;
}
