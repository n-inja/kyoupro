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
  vector<ll> c(n), d(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> d[i];
    ans += d[i];
  }
  ans--;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += c[i] * d[i];
  }
  while (sum > 9) {
    ll cnt = sum / 10;
    ans += cnt;
    sum -= cnt * 9;
  }
  cout << ans << endl;
  return 0;
}
