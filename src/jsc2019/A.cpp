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
  vector<ll> a(n), b(m);
  map<int, int> ainv, binv;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) ainv[a[i]] = i;
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < m; i++) binv[b[i]] = i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int al = 0, ar = n - 1;
  int bl = 0, br = m - 1;
  while (al < ar && bl < br) {
    if (a[al] + b[br] == a[ar] + b[bl]) {
      cout << ainv[a[al]] << " " << binv[b[br]] << " " << ainv[a[ar]] << " " << binv[b[bl]] << endl;
      return 0;
    }
    if (a[ar] - a[al] > b[br] - b[bl]) {
      if (a[ar] - a[ar - 1] > a[al + 1] - a[al]) {
        ar--;
      } else {
        al++;
      }
    } else {
      if (b[br] - b[br - 1] > b[bl + 1] - b[bl]) {
        br--;
      } else {
        bl++;
      }
    }
  }
  map<int, pair<int, int>> amp, bmp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < min(n, i + 300); j++) {
      amp[a[j] - a[i]] = make_pair(a[i], a[j]);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < min(n, i + 300); j++) {
      bmp[b[j] - b[i]] = make_pair(b[i], b[j]);
    }
  }
  for (auto &it : amp) {
    for (int i = 0; i < m; i++) {
      auto bit = lower_bound(b.begin() + i + 1, b.end(), b[i] + it.first);
      if (bit != b.end() && *bit == b[i] + it.first) {
        cout << ainv[it.second.first] << " " << binv[*bit] << " " << ainv[it.second.second] << " " << binv[b[i]]
             << endl;
        return 0;
      }
    }
  }
  for (auto &it : bmp) {
    for (int i = 0; i < n; i++) {
      auto ait = lower_bound(a.begin() + i + 1, a.end(), a[i] + it.first);
      if (ait != a.end() && *ait == a[i] + it.first) {
        cout << ainv[*ait] << " " << binv[it.second.first] << " " << ainv[a[i]] << " " << binv[it.second.second]
             << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
