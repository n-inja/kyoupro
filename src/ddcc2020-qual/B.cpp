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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll sum = 0, lsum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  ll ans = 1LL << 60;
  for (int i = 0; i < n - 1; i++) {
    lsum += a[i];
    sum -= a[i];
    ans = min(ans, abs(lsum - sum));
  }
  cout << ans << endl;
  return 0;
}
