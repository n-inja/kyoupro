#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int h, w;
vector<string> mp;
long long ans = 0;
vector<vector<bool>> used;
int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};
pair<int, int> dfs(int i, int j, char c) {
  if (used[i][j])
    return make_pair(0, 0);
  if (mp[i][j] != c)
    return make_pair(0, 0);
  used[i][j] = true;
  pair<int, int> ret;
  char d = c == '#' ? '.' : '#';
  for (int k = 0; k < 4; k++) {
    int y = i + hy[k], x = j + hx[k];
    if (y < 0 || y >= h || x < 0 || x >= w)
      continue;
    auto p = dfs(y, x, d);
    ret.first += p.first;
    ret.second += p.second;
  }
  if (c == '#')
    ret.first++;
  else
    ret.second++;
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  mp.resize(h);
  used.resize(h);
  for (int i = 0; i < h; i++) {
    used[i].resize(w);
    cin >> mp[i];
  }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (used[i][j])
        continue;
      auto p = dfs(i, j, mp[i][j]);
      ans += (ll)p.first * p.second;
    }

  cout << ans << endl;
  return 0;
}
