#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n;
vector<ll> s;
vll sums;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  sums.resize(n + 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j += i) sums[i] += s[j];
  }

  ll ans = 0;
  if (n % 2 == 0) {
    ll sum = 0;
    for (auto &v : s) sum += v;
    ans = max(ans, sum);
  }
  for (int c = 1; c <= n; c++) {
    vector<ll> d;
    for (int k = 0; k * c < n; k++) {
      int a = n - 1 - c * k;
      int b = a - c;
      if (b <= 0 || b >= n || a <= 0 || a >= n) continue;
      if ((c * k - a) % c == 0) {
        int k2 = (c * k - a) / c;
        if (k2 < k && k2 >= 0) continue;
      }
      if (k == 0) {
        d.push_back(s[a]);
      } else {
        d.push_back(d[d.size() - 1] + s[a] + s[c * k]);
      }
      ans = max(ans, d[d.size() - 1]);
    }
  }

  cout << ans << endl;

  return 0;
}
