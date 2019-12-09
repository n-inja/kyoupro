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
  vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> a[i][j];
  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> b[i][j];
  int offset = 13000;
  vector<vector<bitset<26000>>> can(h, vector<bitset<26000>>(w));
  can[0][0][offset + (a[0][0] - b[0][0])] = true;
  can[0][0][offset + (b[0][0] - a[0][0])] = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == j && i == 0) continue;
      if (i > 0) {
        if (a[i][j] - b[i][j] >= 0) {
          can[i][j] |= can[i - 1][j] << (a[i][j] - b[i][j]);
          can[i][j] |= can[i - 1][j] >> (a[i][j] - b[i][j]);
        } else {
          can[i][j] |= can[i - 1][j] << (b[i][j] - a[i][j]);
          can[i][j] |= can[i - 1][j] >> (b[i][j] - a[i][j]);
        }
      }
      if (j > 0) {
        if (a[i][j] - b[i][j] >= 0) {
          can[i][j] |= can[i][j - 1] << (a[i][j] - b[i][j]);
          can[i][j] |= can[i][j - 1] >> (a[i][j] - b[i][j]);
        } else {
          can[i][j] |= can[i][j - 1] << (b[i][j] - a[i][j]);
          can[i][j] |= can[i][j - 1] >> (b[i][j] - a[i][j]);
        }
      }
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < 12900; i++) {
    if (can[h - 1][w - 1][offset + i] || can[h - 1][w - 1][offset - i]) {
      ans = min(ans, i);
    }
  }
  cout << ans << endl;
  return 0;
}
