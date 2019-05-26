#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll n, m;
vll a;
vector<pair<ll, ll>> bc;
map<ll, ll> mp;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  bc.resize(m);
  for (int i = 0; i < m; i++) cin >> bc[i].first >> bc[i].second;
  for (int i = 0; i < n; i++) mp[-a[i]]++;
  for (auto &v : bc) mp[-v.second] += v.first;
  ll sum = 0, c = 0;
  for (auto &v: mp) {
    sum -= v.first * min(n - c, v.second);
    c += min(n - c, v.second);
  }
  cout << sum << endl;

  return 0;
}
