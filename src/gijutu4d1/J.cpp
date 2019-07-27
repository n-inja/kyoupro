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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  ll asum = 0, bsum = 0;
  for (int i = 0; i < n; i++) asum += a[i];
  for (int i = 0; i < m; i++) bsum += b[i];
  if (asum <= bsum + 1) {
    cout << "0.0000000000" << endl;
    return 0;
  }
  double h = asum - bsum - 0.9;

  vector<double> v;
  for (int i = 0; i < (1 << m); i++) {
    ll A = 0, B = 0;
    for (int j = 0; j < m; j++) if (i & (1 << j)) A += b[j]; else B += b[j];
    if (A <= B) continue;
    if (A == 0 || B == 0) continue;
    v.push_back(A - B);
  }
  double sum = v.size();
  sort(v.begin(), v.end());
  double ans = 0.;
  for (int i = 0; i < (1 << n); i++) {
    ll A = 0, B = 0;
    for (int j = 0; j < n; j++) if (i & (1 << j)) A += a[j]; else B += a[j];
    if (A <= B) continue;
    if (A == 0 || B == 0) continue;
    ll C = A - B;

    auto bit = lower_bound(v.begin(), v.end(), C - h);
    auto eit = lower_bound(v.begin(), v.end(), C + h);
    ans = max(ans, (eit - bit) / sum);
  }

  printf("%.12lf\n", ans);
  return 0;
}
