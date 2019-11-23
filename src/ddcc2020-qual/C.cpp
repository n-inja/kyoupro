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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> mp(h);
  for (int i = 0; i < h; i++) cin >> mp[i];
  vector<vector<int>> ans(h, vector<int>(w));
  vector<int> cur(w);

  int now = 0, min_id = w;

  for (int i = 0; i < h; i++) {
    int cnt = 0;
    int fst = now;
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == '#') {
        now++;
        cnt++;
      }
    }
    if (fst == now) {
      if (i > 0) {
        ans[i] = ans[i - 1];
      }
    } else {
      min_id = min(min_id, i);
      int j = 0;
      bool ok = false;
      while (fst < now) {
        for (; j < w; j++) {
          ans[i][j] = fst + 1;
          if (mp[i][j] == '#') {
            fst++;
            if (ok) {
              ans[i][j] = fst;
            } else {
              ok = true;
            }
            j++;
            break;
          }
        }
      }
      j--;
      for (; j < w; j++) {
        ans[i][j] = fst;
      }
    }
  }
  for (int i = min_id - 1; i >= 0; i--) {
    ans[i] = ans[i + 1];
  }
  for (int i = 0; i < h; i++) {
    cout << ans[i][0];
    for (int j = 1; j < w; j++) cout << " " << ans[i][j];
    cout << endl;
  }
  return 0;
}
