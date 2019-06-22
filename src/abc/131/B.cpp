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
  ll n, l;
  cin >> n >> l;
  vll a(n);
  for (int i = 0; i < n; i++) a[i] = l + i;
  ll ans = 0, diff = 100000000;
  vll s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  for (int i = 0; i < n; i++) {
    if (diff > abs(a[i])) {
      diff = abs(a[i]);
      ans = s[n] - a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
