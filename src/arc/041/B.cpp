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
  vector<string> mp(n), ans(n, string(m, '0'));
  for (int i = 0; i < n; i++) cin >> mp[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mp[i][j] != '0') {
        int diff = mp[i][j] - '0';
        ans[i + 1][j] += diff;
        mp[i][j] -= diff;
        mp[i + 1][j - 1] -= diff;
        mp[i + 1][j + 1] -= diff;
        mp[i + 2][j] -= diff;
      }
    }
  for (auto &v : ans) cout << v << endl;
  return 0;
}
