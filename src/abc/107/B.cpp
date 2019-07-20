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
  string s(w, '.');
  for (int i = 0; i < h; i++) {
    cin >> mp[i];
    if (mp[i] == s) {
      i--;
      h--;
    }
  }
  set<int> oks;
  for (int i = 0; i < w; i++) {
    bool ok = false;
    for (int j = 0; j < h; j++) if (mp[j][i] == '#') ok = true;
    if (ok) oks.insert(i);
  }
  for (int i = 0; i < h; i++) {
    for (auto &j : oks) cout << mp[i][j];
    cout << endl;
  }
  return 0;
}
