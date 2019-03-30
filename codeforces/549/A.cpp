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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, k, a, b;
  cin >> n >> k >> a >> b;
  vll as;
  if (a == (n * k - a)) {
    as.push_back(a);
  } else {
    as.push_back(a);
    as.push_back(n * k - a);
  }
  vll bs;
  if (b == (n * k - b)) {
    bs.push_back(b);
  } else {
    bs.push_back(b);
    bs.push_back(n * k - b);
  }
  ll x = n * k, y = 0;
  for (auto &c : as) {
    for (auto &d : bs) {
      for (int i = 0; i < n; i++) {
        ll e = (d - c + n * k + i * k) % (n * k);
        if (e == 0)
          e += n * k;
        x = min(x, (n * k) / gcd(n * k, e));
        y = max(y, (n * k) / gcd(n * k, e));
      }
    }
  }
  cout << x << " " << y << endl;

  return 0;
}
