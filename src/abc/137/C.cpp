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
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
  sort(v.begin(), v.end());
  ll ans = 0;
  bool same = false;
  ll c = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) {
      if (same) {
        c++;
      } else {
        c = 1;
        same = true;
      }
    } else {
      ans += c * (c + 1) / 2;
      c = 0;
    }
  }
  ans += c * (c + 1) / 2;
  cout << ans << endl;
  return 0;
}
