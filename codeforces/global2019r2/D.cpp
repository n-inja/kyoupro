#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  vll d;
  for (int i = 0; i < n - 1; i++) {
    d.push_back(v[i + 1] - v[i]);
  }
  sort(d.begin(), d.end());
  vll sd(n);
  for (int i = 0; i < n - 1; i++) {
    sd[i + 1] = sd[i] + d[i];
  }
  int q;
  cin >> q;
  vll ans;
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    auto diff = upper_bound(d.begin(), d.end(), r - l) - d.begin();
    ans.push_back((r - l + 1) * (n - diff) + sd[diff]);
  }
  cout << ans[0];
  for (int i = 1; i < q; i++)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}
