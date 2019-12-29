#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll f(ll n, ll a, ll b) {
  if (abs(b - a) % 2 == 0) {
    return abs(b - a) / 2;
  } else {
    if (b < a) swap(a, b);
    return min(a + f(n, 1, b - a), n - b + 1 + f(n, a + n - b + 1, n));
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, a, b;
  cin >> n >> a >> b;
  cout << f(n, a, b) << endl;
  return 0;
}
