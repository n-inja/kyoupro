#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int hx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int hy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for (int i = 0; i < h; i++) cin >> mp[i];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == '.') {
        int c = 0;
        for (int k = 0; k < 8; k++) {
          int ni = i + hx[k], nj = j + hy[k];
          if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
          if (mp[ni][nj] == '#') c++;
        }
        mp[i][j] = '0' + c;
      }
    }
  }
  for (int i = 0; i < h; i++) cout << mp[i] << endl;

  return 0;
}
