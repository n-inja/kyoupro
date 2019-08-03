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
  int n, q;
  cin >> n >> q;
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  vector<ll> t(q), l(q), r(q);
  for (int i = 0; i < q; i++) cin >> t[i] >> l[i] >> r[i];
  vector<ll> x(n + 1);
  x[0] = 0;
  for (int i = 0; i < n; i++) x[i + 1] = x[i] + d[i];

  for (int i = 0; i < q; i++) {
    auto eit = lower_bound(x.begin(), x.end(), t[i]);
    cout << (upper_bound(x.begin(), eit, t[i] - l[i]) - lower_bound(x.begin(), eit, t[i] - r[i])) << endl;
  }

  return 0;
}
