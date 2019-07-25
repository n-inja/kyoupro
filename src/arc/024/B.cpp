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
  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[c[i]]++;
  if (mp[0] == n || mp[1] == n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) c.push_back(c[i]);
  int bef = c[0], cnt = 0;
  int ans = 1;
  for (int i = 0; i < 2 * n; i++) {
    if (c[i] == bef) {
      cnt++;
    } else {
      ans = max(ans, cnt);
      cnt = 1;
      bef = c[i];
    }
  }
  if (ans <= 2) {
    cout << 1 << endl;
  } else {
    if (ans % 2 == 0) ans--;
    cout << ans / 2 + 1 << endl;
  }
  return 0;
}
