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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) sum += a[i];

  vector<ll> div;
  for (ll i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      div.push_back(i);
      if (sum / i != i) {
        div.push_back(sum / i);
      }
    }
  }
  ll ans = 1;
  vector<ll> rem(n);
  for (auto &d : div) {
    for (int i = 0; i < n; i++) rem[i] = a[i] % d;
    sort(rem.begin(), rem.end());
    int bj = n - 1;
    ll c = 0;
    for (int i = 0; i < bj; i++) {
      c += rem[i];
      while (i < bj && rem[bj] + rem[i] > d) {
        rem[i] -= d - rem[bj];
        rem[bj] = d;
        bj--;
      }
      if (i < bj) {
        rem[bj] += rem[i];
        rem[i] = 0;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      if (rem[i] % d != 0) ok = false;
    if (ok && c <= k) {
      ans = max(ans, d);
    }
  }
  cout << ans << endl;

  return 0;
}
