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
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  int x1 = xb - xa, y1 = yb - ya;
  int x2 = xc - xa, y2 = yc - ya;
  printf("%.9lf\n", abs(x1 * y2 - x2 * y1) / 2.);

  return 0;
}
