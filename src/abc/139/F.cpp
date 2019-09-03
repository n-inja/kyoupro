#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
double eps = 0.0000000000001;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<long long, long long>> ps;
  vector<pair<long long, long long>> qs;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
    } else {
      ps.emplace_back(x, y);
      qs.emplace_back(x, y);
      qs.emplace_back(-x, -y);
      qs.emplace_back(-y, x);
      qs.emplace_back(y, -x);
    }
  }
  n = ps.size();
  long long ans = 0.;
  for (int i = 0; i < qs.size(); i++) {
    long long x = 0, y = 0, dx1 = 0, dx2 = 0, dy1 = 0, dy2 = 0;
    for (int j = 0; j < n; j++) {
      if (qs[i].first * ps[j].first + qs[i].second * ps[j].second > 0) {
        x += ps[j].first;
        y += ps[j].second;
      }
      if (qs[i].first * ps[j].first + qs[i].second * ps[j].second == 0) {
        if (qs[i].first * ps[j].second - qs[i].second * ps[j].first > 0) {
          dx1 += ps[j].first;
          dy1 += ps[j].second;
        } else {
          dx2 += ps[j].first;
          dy2 += ps[j].second;
        }
      }
    }
    ans = max(ans, x * x + y * y);
    ans = max(ans, (x + dx1) * (x + dx1) + (y + dy1) * (y + dy1));
    ans = max(ans, (x + dx2) * (x + dx2) + (y + dy2) * (y + dy2));
  }
  printf("%.20lf\n", (double) sqrt((long double) ans));
  return 0;
}
