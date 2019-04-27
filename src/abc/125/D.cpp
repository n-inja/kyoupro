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
  ll n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      ans += a[i];
    } else if (a[i] <= 0 && a[i + 1] <= 0) {
      ans -= a[i] + a[i + 1];
      i++;
    } else if (a[i] <= 0 && a[i + 1] > 0) {
      ans += abs(a[i] + a[i + 1]);
      i++;
    } else {
      ans += a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
