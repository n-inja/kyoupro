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
  int a, b, n;
  cin >> a >> b >> n;
  if (a > b) swap(a, b);
  for (int i = 0; i < n; i++) {
    int c, d;
    cin >> c >> d;
    if (c > d)
      swap(c, d);
    auto f = [&](double theta) {
      double y = b * sin(theta) + a * cos(theta);
      if (y >= d) return true;
      else return false;
    };
    double l = 0., r = M_PI_2;
    if (!f(r)) {
      if (a <= c && b <= d) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      continue;
    }
    for (int j = 0; j < 50; j++) {
      double m = (r + l) / 2;
      if (f(m)) {
        r = m;
      } else {
        l = m;
      }
    }
    double e = b * cos(l) + a * sin(l);
    if (e <= c) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
