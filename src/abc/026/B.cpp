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
  vector<double> r(n + 1);
  r[0] = 0;
  for (int i = 0; i < n; i++) cin >> r[i + 1];
  sort(r.begin(), r.end());
  double ans = 0;
  for (int i = 0; i < n; i++) {
    if ((n - i + 1) % 2 == 0)
      ans += r[i + 1] * r[i + 1] * M_PI - r[i] * r[i] * M_PI;
  }
  printf("%.9lf\n", ans);
  return 0;
}
