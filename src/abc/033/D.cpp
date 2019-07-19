#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

long double eps = 0.000000000000001;

struct N {
  long double x, y;
};

int f(vector<long double> &v, pair<long double, long double> r) {
  int m = lower_bound(v.begin(), v.end(), r.second) - lower_bound(v.begin(), v.end(), r.first);
  if (r.first < -M_PI) {
    m += lower_bound(v.begin(), v.end(), r.second + M_PI * 2) - lower_bound(v.begin(), v.end(), r.first + M_PI * 2);
  }
  if (r.second > M_PI + eps) {
    m += lower_bound(v.begin(), v.end(), r.second - M_PI * 2) - lower_bound(v.begin(), v.end(), r.first - M_PI * 2);
  }
  return m;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<N> ps(n);
  for (int i = 0; i < n; i++) cin >> ps[i].x >> ps[i].y;
  ll t1 = 0, t2 = 0, t3 = 0;
  for (int i = 0; i < n; i++) {
    vector<long double> ns;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      ns.push_back(atan2(ps[j].y - ps[i].y, ps[j].x - ps[i].x));
    }
    sort(ns.begin(), ns.end());

    for (int j = 0; j < n - 1; j++) {
      long double t = ns[j];
      pair<long double, long double> r1(t - M_PI_2 - eps, t + M_PI_2 + eps);
      pair<long double, long double> r2(t - M_PI_2 - eps, t - M_PI_2 + eps);
      pair<long double, long double> r3(t + M_PI_2 - eps, t + M_PI_2 + eps);
      int tt1 = f(ns, r1);
      int tt3 = f(ns, r2) + f(ns, r3);
      t2 += n - 1 - tt1;
      t3 += tt3;
    }
  }
  t2 /= 2;
  t3 /= 2;
  t1 = n * (n - 1) * (n - 2) / 6 - t2 - t3;
  cout << t1 << " " << t3 << " " << t2 << endl;
  return 0;
}
