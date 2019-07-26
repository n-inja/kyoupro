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
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ans = max(ans, a + b + c + d + e / 900 * 110);
  }
  printf("%.12lf\n", ans);
  return 0;
}
