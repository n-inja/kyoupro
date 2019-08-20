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
  string s, t;
  cin >> s >> t;
  ll ans = 0;
  int n = s.size();
  int m = t.size();
  vector<vector<int>> cindex(26);
  for (int i = 0; i < n; i++) {
    cindex[s[i] - 'a'].push_back(i);
  }
  int now = -1;
  for (int i = 0; i < m; i++) {
    if (cindex[t[i] - 'a'].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    auto it = upper_bound(cindex[t[i] - 'a'].begin(), cindex[t[i] - 'a'].end(), now);
    if (it == cindex[t[i] - 'a'].end()) {
      now = cindex[t[i] - 'a'][0];
      ans += n;
    } else {
      now = *it;
    }
  }
  ans += now + 1;
  cout << ans << endl;
  return 0;
}
