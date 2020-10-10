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
  int ans = 0;
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w; j++)
      if (mp[i][j] == '.' && mp[i + 1][j] == '.')ans++;
  }
  for (int i = 0; i < h; i++) for (int j = 0; j < w - 1; j++) if (mp[i][j] == '.' && mp[i][j + 1] == '.') ans++;
  cout << ans << endl;
  return 0;
}
