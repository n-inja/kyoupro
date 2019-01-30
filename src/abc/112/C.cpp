#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> h(n), x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> h[i];
  ll ans = 0, ansx = 0, ansy = 0;
  for (int gx = 0; gx <= 100; gx++)
    for (int gy = 0; gy <= 100; gy++) {
      ll g = 0;
      for (int i = 0; i < n; i++)
        if (h[i])
          g = max(g, h[i] + abs(x[i] - gx) + abs(y[i] - gy));
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (max(g - abs(x[i] - gx) - abs(y[i] - gy), 0LL) != h[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        if (ans < g) {
          ans = g;
          ansx = gx;
          ansy = gy;
        }
      }
    }
  cout << ansx << " " << ansy << " " << ans << endl;
  return 0;
}
