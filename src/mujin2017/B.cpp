#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int solve(int n, vector<string> &mp) {
  bool ok = false;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (mp[i][j] == '#') ok = true;
  if (!ok) {
    return -1;
  }
  int ans = n * 2;
  bool full = false;
  int hok = 0;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) if (mp[j][i] == '.') ok = false;
    if (ok) hok++;
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < n; j++) if (mp[i][j] == '#') c++;
    bool ok = false;
    for (int j = 0; j < n; j++) if (mp[j][i] == '#') ok = true;
    if (ok) {
      ans = min(ans, 2 * n - c - hok);
    } else {
      ans = min(ans, 2 * n - c - hok + 1);
    }
    if (c == n) full = true;
  }
  if (full) {
    int c = 0;
    for (int i = 0; i < n; i++) {
      bool ng = false;
      for (int j = 0; j < n; j++) {
        if (mp[j][i] == '.') ng = true;
      }
      if (!ng) c++;
    }
    ans = min(ans, n - c);
  }
  return ans;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> mp(n);
  for (int i = 0; i < n; i++) cin >> mp[i];
  cout << solve(n, mp) << endl;

  /*
  for (int i = 0; i < (1 << 9); i++) {
    i = 6;
    for (int j = 0; j < 9; j++) if ((i >> j) & 1) mp[j / 3][j % 3] = '#'; else mp[j / 3][j % 3] = '.';
    cout << solve(n, mp) << endl;
    for (auto &s : mp) cerr << s << endl;
    break;
  }
   */

  return 0;
}
