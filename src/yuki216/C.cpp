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
  int m = 500001;
  vector<bool> used(m);
  vector<ll> p;
  used[0] = used[1] = true;
  for (int i = 2; i < m; i++) {
    if (used[i]) continue;
    p.push_back(i);
    for (int j = 1; i * j < m; j++) used[i * j] = true;
  }
  set<ll> s;
  for (auto &i : p) s.insert(i * i);
  ll ans = 0;
  if (n < 2) {
    cout << 0 << endl;
    return 0;
  }
  for (auto &i : p) {
    if (i > n) break;
    if (s.find(i + 2) != s.end()) {
      if (i != 2) ans += 2;
      else ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
