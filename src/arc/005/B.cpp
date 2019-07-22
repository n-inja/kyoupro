#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int hx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int hy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

string dir[8] = {
    "R",
    "L",
    "U",
    "D",
    "RU", "RD",
    "LU", "LD"
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int x, y;
  string w;
  cin >> x >> y >> w;
  int d = 0;
  for (int i = 0; i < 8; i++) if (w == dir[i]) d = i;
  x += 6, y += 6;
  vector<string> mp(23);
  for (int i = 0; i < 9; i++) cin >> mp[i + 7];
  for (int i = 0; i < 9; i++) {
    string s = mp[i + 7].substr(1, 7);
    reverse(s.begin(), s.end());
    mp[i + 7] = s + mp[i + 7] + s;
  }
  for (int i = 0; i < 7; i++) {
    mp[i] = mp[14 - i];
    mp[i + 16] = mp[14 - i];
  }
  string ans;
  for (int i = 0; i < 4; i++) {
    ans.push_back(mp[y][x]);
    y += hy[d];
    x += hx[d];
  }
  cout << ans << endl;

  return 0;
}
