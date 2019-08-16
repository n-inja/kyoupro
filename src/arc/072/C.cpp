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
  ll D;
  cin >> n >> D;
  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  vector<ll> pos(n + 1), ng(n + 1);
  pos[0] = D;
  ng[n] = 1;
  for (int i = 0; i < n; i++) {
    pos[i + 1] = min(abs(pos[i] - d[i]), pos[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (ng[i + 1] <= d[i] / 2) {
      ng[i] = ng[i + 1];
    } else {
      ng[i] = ng[i + 1] + d[i];
    }
  }

  cin >> q;
  vector<ll> a(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i];
    a[i]--;
    if (pos[a[i]] >= ng[a[i] + 1]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
