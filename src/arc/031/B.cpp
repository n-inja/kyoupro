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
  int hx[4] = {0, 0, 1, -1};
  int hy[4] = {1, -1, 0, 0};
  vector<string> mp(10);
  vector<vector<bool>> used(10, vector<bool>(10));
  function<int(int, int)> dfs;
  dfs = [&](int i, int j) {
    if (used[i][j] || mp[i][j] == 'x') return 0;
    used[i][j] = true;
    int ret = 1;
    for (int k = 0; k < 4; k++) {
      int ni = i + hx[k], nj = j + hy[k];
      if (ni < 0 || ni >= 10 || nj < 0 || nj >= 10) continue;
      ret += dfs(ni, nj);
    }
    return ret;
  };
  int all = 0;
  for (int i = 0; i < 10; i++) cin >> mp[i];
  for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (mp[i][j] == 'o')all++;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (mp[i][j] == 'o') continue;
      mp[i][j] = 'o';
      used = vector<vector<bool>>(10, vector<bool>(10));
      int sum = dfs(i, j);
      if (sum == all + 1) {
        cout << "YES" << endl;
        return 0;
      }
      mp[i][j] = 'x';
    }
  }
  cout << "NO" << endl;
  return 0;
}
