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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n), sub(n - 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll sum = 0;
  for (int i = 1; i < n; i++) {
    sum += sub[i - 1] = a[i] - a[i - 1];
  }
  sort(sub.rbegin(), sub.rend());
  ll ans = sum;
  for (int i = 0; i < k - 1; i++) ans -= sub[i];
  cout << ans << endl;

  return 0;
}
