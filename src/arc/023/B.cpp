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
  int r, c, d;
  cin >> r >> c >> d;
  vector<vector<ll>> a(r, vector<ll>(c));
  for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> a[i][j];
  ll ans = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      ll rest = d - i - j;
      if (rest < 0) continue;
      if (rest % 2 == 1) continue;
      ans = max(ans, a[i][j]);
    }
  cout << ans << endl;
  return 0;
}
