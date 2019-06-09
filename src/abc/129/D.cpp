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
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (int i = 0; i < h; i++) cin >> mp[i];
  vector<vector<ll>> r(h), l(h), u(w), d(w);
  for (int i = 0; i < h; i++) {
    r[i].resize(w + 1);
    l[i].resize(w + 1);
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == '.') r[i][j + 1] = r[i][j] + 1;
      if (mp[i][w - 1 - j] == '.') l[i][j + 1] = l[i][j] + 1;
    }
  }
  for (int i = 0; i < w; i++) {
    u[i].resize(h + 1);
    d[i].resize(h + 1);
    for (int j = 0; j < h; j++) {
      if (mp[j][i] == '.') d[i][j + 1] = d[i][j] + 1;
      if (mp[h - 1 - j][i] == '.') u[i][j + 1] = u[i][j] + 1;
    }
  }
  ll ans = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == '.') {
        ans = max(ans, r[i][j] + l[i][w - j - 1] + d[j][i] + u[j][h - i - 1] + 1);
      }
    }
  cout << ans << endl;
  return 0;
}
