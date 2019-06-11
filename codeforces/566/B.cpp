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
  int c = 0;
  for (int i = 1; i < h - 1; i++) {
    for (int j = 1; j < w - 1; j++) {
      if (mp[i][j] == '*' && mp[i + 1][j] == '*' && mp[i][j + 1] == '*' && mp[i - 1][j] == '*' && mp[i][j - 1] == '*') {
        if (c) break;
        c++;
        for (int k = i - 1; k >= 0; k--) {
          if (mp[k][j] == '.') break;
          mp[k][j] = '.';
        }
        for (int k = i + 1; k < h; k++) {
          if (mp[k][j] == '.') break;
          mp[k][j] = '.';
        }
        for (int k = j - 1; k >= 0; k--) {
          if (mp[i][k] == '.') break;
          mp[i][k] = '.';
        }
        for (int k = j + 1; k < w; k++) {
          if (mp[i][k] == '.') break;
          mp[i][k] = '.';
        }
        mp[i][j] = '.';
      }
    }
  }
  int d = 0;
  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (mp[i][j] == '*') d++;
  if (d == 0 && c) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
