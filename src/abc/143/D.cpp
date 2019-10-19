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
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  ll ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      ll mint = max(v[i] - v[j], v[j] - v[i]);
      ll maxt = v[i] + v[j];
      ll t = lower_bound(v.begin(), v.end(), maxt) - upper_bound(v.begin(), v.end(), mint);
      if (mint < v[i] && v[i] < maxt) t--;
      if (mint < v[j] && v[j] < maxt) t--;
      ans += t;
    }
  cout << ans / 6 << endl;
  return 0;
}
