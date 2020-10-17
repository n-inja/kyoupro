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
  long long x, y, a, b;
  cin >> x >> y >> a >> b;
  double yy = y;
  long long ans = 0;
  long long xx = x;
  long long ai = 0;
  for (int i = 0; i < 1000000; i++) {
    ans = max(ans, ai + (y - xx - 1) / b);
    ai++;
    double xxx = xx;
    xxx *= a;
    if (xxx >= yy) break;
    xx *= a;
    if (xx >= y) break;
  }
  cout << ans << endl;
  return 0;
}
