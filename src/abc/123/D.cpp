#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll x[3], k;
vvl a(3);

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> x[0] >> x[1] >> x[2] >> k;
  a[0].resize(x[0]);
  a[1].resize(x[1]);
  a[2].resize(x[2]);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < x[i]; j++)
      cin >> a[i][j];
  for (int i = 0; i < 3; i++)
    sort(a[i].begin(), a[i].end());
  vector<ll> ns;
  for (int i = 0; i < x[0]; i++)
    for (int j = 0; j < x[1]; j++)
      ns.push_back(a[0][i] + a[1][j]);
  sort(ns.begin(), ns.end());
  reverse(ns.begin(), ns.end());
  vector<ll> ans;
  for (int i = 0; i < k && i < ns.size(); i++) {
    for (int j = x[2] - 1; j >= 0; j--) {
      ans.push_back(ns[i] + a[2][j]);
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < k; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
