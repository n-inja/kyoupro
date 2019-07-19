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
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  pair<ll, ll> ans(a * 100, 0);
  for (int i = 0; i <= f / 100 / a; i++) {
    for (int j = 0; j <= f / 100 / b; j++) {
      ll rest = f - a * 100 * i - b * 100 * j;
      if (rest < 0) continue;
      for (int k = 0; k <= rest / c; k++)
        for (int l = 0; l <= (rest - k * c) / d; l++) {
          ll w = a * 100 * i + b * 100 * j;
          ll s = c * k + d * l;
          if (e * w < s * 100) continue;
          if (ans.second * (w + s) < s * ans.first) {
            ans.second = s;
            ans.first = w + s;
          }
        }
    }
  }
  cout << ans.first << " " << ans.second << endl;

  return 0;
}
