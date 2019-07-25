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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll l = 0, r = n;
  auto f = [&](ll m) {
    map<ll, int> mp;
    int c = 0;
    for (int i = 0; i < m; i++) {
      mp[a[i]]++;
      if (mp[a[i]] == 2) c++;
    }
    if (c == 0) return true;
    for (int i = m; i < n; i++) {
      mp[a[i - m]]--;
      if (mp[a[i - m]] == 1) c--;
      mp[a[i]]++;
      if (mp[a[i]] == 2) c++;
      if (c == 0) return true;
    }
    return false;
  };
  if (f(n)) {
    cout << n << endl;
    return 0;
  }
  while (r - l > 1) {
    ll m = (r + l) / 2;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
