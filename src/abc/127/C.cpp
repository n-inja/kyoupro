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
  int _, n;
  cin >> _ >> n;
  vll v(101010);
  for (int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;
    l--;
    v[l]++;
    v[r]--;
  }
  ll ans = 0, sum = 0;
  for (int i = 0; i < 101010; i++) {
    sum += v[i];
    if (sum == n) ans++;
  }
  cout << ans << endl;
  return 0;
}
