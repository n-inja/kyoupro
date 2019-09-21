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
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<vector<int>> mp(h, vector<int>(w));
  for (int i = 0; i < h - b; i++) for (int j = 0; j < w - a; j++) mp[i][j] = 1;
  for (int i = h - b; i < h; i++) for (int j = w - a; j < w; j++) mp[i][j] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) cout << mp[i][j];
    cout << endl;
  }
  return 0;
}
