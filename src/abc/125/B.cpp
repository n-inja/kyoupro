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
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll c;
    cin >> c;
    v[i] -= c;
    ans += max(0LL, v[i]);
  }
  cout << ans << endl;

  return 0;
}
