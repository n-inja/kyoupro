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
  double n, m;
  cin >> n >> m;
  n += m / 60;
  if (n > 12) n -= 12;
  double ans = abs(n / 12 * 360 - m / 60 * 360);
  ans = min(ans, 360 - ans);
  printf("%.9lf\n", ans);
  return 0;
}
