#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<int> ans;
  k--;
  for (int i = 0; i < n; i++) cin >> a[i];
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum % 2 == 1 && k) {
      ans.push_back(i + 1);
      k--;
      sum = 0;
    }
  }
  if (k > 0 || sum % 2 == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << n << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
