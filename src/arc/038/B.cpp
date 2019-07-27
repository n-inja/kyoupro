#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int hx[3] = {0, 1, 1};
int hy[3] = {1, 0, 1};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> mp(h + 1);
  for (int i = 0; i < h; i++) {
    cin >> mp[i];
    mp[i].push_back('#');
  }
  mp[h] = string(w + 1, '#');
  vector<vector<int>> memo(h + 1, vector<int>(w + 1, -1));
  function<int(int, int)> dfs;
  dfs = [&](int i, int j) {
    if (memo[i][j] >= 0) return memo[i][j];
    if (mp[i][j] == '#') return 2;
    vector<int> s;
    for (int k = 0; k < 3; k++) {
      int r = dfs(i + hx[k], j + hy[k]);
      if (r == 2) continue;
      s.push_back(r);
    }
    if (s.size() == 0) return memo[i][j] = 0;
    if (*min_element(s.begin(), s.end()) == 0) return memo[i][j] = 1;
    return memo[i][j] = 0;
  };
  if (dfs(0, 0)) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}
