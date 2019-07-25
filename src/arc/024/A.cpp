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
  int l, r;
  cin >> l >> r;
  vector<ll> ls(l), rs(r);
  for (int i = 0; i < l; i++) cin >> ls[i];
  for (int i = 0; i < r; i++) cin >> rs[i];
  map<ll, int> mp;
  for (int i = 0; i < l; i++) mp[ls[i]]++;
  ll ans = 0;
  for (int i = 0; i < r; i++) {
    if (mp[rs[i]]) {
      mp[rs[i]]--;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
