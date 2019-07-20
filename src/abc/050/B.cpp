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
  vector<ll> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];
  ll sum = 0;
  for (int i = 0; i < n; i++) sum += t[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    ll j, x;
    cin >> j >> x;
    j--;
    cout << sum - t[j] + x << endl;
  }
  return 0;
}
