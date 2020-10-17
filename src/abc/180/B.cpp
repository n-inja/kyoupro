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
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long man = 0, c = 0;
  double yu = 0;
  for (int i = 0; i < n; i++) {
    man += abs(a[i]);
    yu += a[i] * a[i];
    c = max(c, abs(a[i]));
  }
  printf("%lld\n%.12lf\n%lld\n", man, sqrt(yu), c);
  return 0;
}
