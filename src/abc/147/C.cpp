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
  int n;
  cin >> n;
  vector<int> bs(n), cs(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int x, y;
      cin >> x >> y;
      if (y) {
        bs[i] |= 1LL << (x - 1);
      } else {
        cs[i] |= 1LL << (x - 1);
      }
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1LL << n); bit++) {
    int b = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (bit & (1LL << i))
        b |= bs[i];
    }
    for (int i = 0; i < n; i++) {
      if (bit & (1LL << i))
        c |= cs[i];
    }
    if (b & c) {
      continue;
    }
    if (c & bit) {
      continue;
    }
    if (b & (~bit)) {
      continue;
    }
    int count = 0;
    for (int k = 0; k < n; k++) if (bit & (1LL << k)) count++;
    ans = max(ans, count);
  }
  cout << ans << endl;
  return 0;
}
