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
  ll ans = 101010;
  ll sum = 0;
  for (int i = 0; i < n; i++) sum += c[i];
  for (int i = 0; i < (1 << n); i++) {
    ll sub = 0;
    for (int j = 0; j < n; j++) if ((i >> j) & 1) sub += c[j];
    ans = min(ans, max(sub, sum - sub));
  }
  cout << ans << endl;
  return 0;
}
