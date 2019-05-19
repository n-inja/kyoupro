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
  int n, k;
  cin >> n >> k;
  vector<double> p(201010);
  p[k] = 1.;
  for (int i = 200000; i > 0; i--) {
    if (i >= k) p[i] = 1.;
    else p[i] = p[i * 2] / 2;
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += p[i + 1];
  }
  ans /= n;
  printf("%.13lf\n", ans);
  return 0;
}
