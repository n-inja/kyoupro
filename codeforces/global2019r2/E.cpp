#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll n;
vll v, w;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  ll ans = 0, internal = 0;
  ll rest = 0;
  for (int i = 0; i < n; i++) {
    ll r = min(v[i] / 2, rest);
    ans += r;
    rest -= r;
    v[i] -= r * 2;
    ans += v[i] / 3;
    rest += v[i] % 3;
  }
  cout << ans << endl;

  return 0;
}
