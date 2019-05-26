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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> p(m);
  vector<int> q(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    p[i].resize(k);
    for (int j = 0; j < k; j++) cin >> p[i][j];
  }
  for (int i = 0; i < m; i++) cin >> q[i];
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    bool ok = true;
    for (int j = 0; j < m; j++) {
      int b = 0;
      for (auto &k : p[j]) {
        b += (i >> (k - 1)) & 1;
      }
      if (b % 2 != q[j]) ok = false;
    }
    if (ok) ans++;
  }

  cout << ans << endl;
  return 0;
}
