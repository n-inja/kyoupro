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
  cin >> n;
  vector<ll> a(n);

  vector<vector<int>> rs, srs;
  vector<int> zero(n), szero(n + 1);
  vector<ll> p;
  vector<bool> used(2001);
  for (int i = 2; i < 2001; i++) {
    if (used[i]) continue;
    p.push_back(i);
    for (int j = i; j < 2001; j += i) used[j] = true;
  }
  for (int i = 0; i < p.size(); i++) {
    rs.emplace_back(n);
    srs.emplace_back(n + 1);
  }

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      zero[i] = 1;
      continue;
    }
    for (int j = 0; j < p.size() && a[i] > 1; j++) {
      int c = 0;
      while (a[i] % p[j] == 0) {
        a[i] /= p[j];
        c++;
      }
      if (c)
        rs[j][i] = c;
    }
  }
  for (int i = 0; i < n; i++) szero[i + 1] = szero[i] + zero[i];
  for (int i = 0; i < p.size(); i++) for (int j = 0; j < n; j++) srs[i][j + 1] = srs[i][j] + rs[i][j];
  cin >> m;
  for (int i = 0; i < m; i++) {
    ll l, r, q;
    cin >> q >> l >> r;
    l--;
    bool breaked = false;
    if (szero[r] - szero[l]) {
      cout << "Yes" << endl;
      continue;
    }
    for (int j = 0; j < p.size() && q > 1; j++) {
      int c = 0;
      while (q % p[j] == 0) {
        q /= p[j];
        c++;
      }
      if (c && srs[j][r] - srs[j][l] < c) {
        breaked = true;
        break;
      }
    }
    if (!breaked && q == 1) cout << "Yes" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
