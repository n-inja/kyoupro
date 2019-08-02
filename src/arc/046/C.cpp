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
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> ab(n), dc(m);
  for (int i = 0; i < n; i++) {
    cin >> ab[i].first >> ab[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> dc[i].second >> dc[i].first;
  }
  sort(ab.begin(), ab.end());
  sort(dc.begin(), dc.end());
  map<ll, int> mp;
  int j = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    while (j < m && ab[i].first >= dc[j].first) {
      mp[dc[j].second]++;
      j++;
    }
    auto it = mp.lower_bound(ab[i].second);
    if (it != mp.end()) {
      ans++;
      if (it->second == 1) {
        mp.erase(it);
      } else {
        it->second--;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
