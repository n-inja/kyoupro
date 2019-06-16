#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  ll x, y;
  char d;
};

double f(pair<double, double> x, double y) {
  return x.first + x.second * y;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> ns(n);
  for (int i = 0; i < n; i++) {
    cin >> ns[i].x >> ns[i].y >> ns[i].d;
  }
  vector<ll> x, xt, xtt, y, yt, ytt;
  for (int i = 0; i < n; i++) {
    if (ns[i].d == 'U') {
      xt.push_back(ns[i].x);
      ytt.push_back(ns[i].y);
    }
    if (ns[i].d == 'R') {
      xtt.push_back(ns[i].x);
      yt.push_back(ns[i].y);
    }
    if (ns[i].d == 'D') {
      xt.push_back(ns[i].x);
      y.push_back(ns[i].y);
    }
    if (ns[i].d == 'L') {
      x.push_back(ns[i].x);
      yt.push_back(ns[i].y);
    }
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  sort(x.begin(), x.end());
  sort(xt.begin(), xt.end());
  sort(xtt.begin(), xtt.end());
  sort(y.begin(), y.end());
  sort(yt.begin(), yt.end());
  sort(ytt.begin(), ytt.end());
  vector<pair<double, double>> xmaxs, xmins, ymaxs, ymins;
  if (x.size()) xmaxs.emplace_back(x[x.size() - 1], 0);
  if (xt.size()) xmaxs.emplace_back(xt[xt.size() - 1], 1);
  if (xtt.size()) xmaxs.emplace_back(xtt[xtt.size() - 1], 2);
  if (x.size()) xmins.emplace_back(x[0], 0);
  if (xt.size()) xmins.emplace_back(xt[0], 1);
  if (xtt.size()) xmins.emplace_back(xtt[0], 2);
  if (y.size()) ymaxs.emplace_back(y[y.size() - 1], 0);
  if (yt.size()) ymaxs.emplace_back(yt[yt.size() - 1], 1);
  if (ytt.size()) ymaxs.emplace_back(ytt[ytt.size() - 1], 2);
  if (y.size()) ymins.emplace_back(y[0], 0);
  if (yt.size()) ymins.emplace_back(yt[0], 1);
  if (ytt.size()) ymins.emplace_back(ytt[0], 2);

  double ans = -1;
  vector<double> t({0., 0.});
  for (int i = 0; i < xmaxs.size(); i++)
    for (int j = i + 1; j < xmaxs.size(); j++) {
      double tt = (xmaxs[i].first - xmaxs[j].first) / (xmaxs[i].second - xmaxs[j].second);
      if (tt < 0.000001) t.push_back(-tt);
    }
  for (int i = 0; i < ymaxs.size(); i++)
    for (int j = i + 1; j < ymaxs.size(); j++) {
      double tt = (ymaxs[i].first - ymaxs[j].first) / (ymaxs[i].second - ymaxs[j].second);
      if (tt < 0.000001) t.push_back(-tt);
    }
  for (int i = 0; i < xmins.size(); i++)
    for (int j = i + 1; j < xmins.size(); j++) {
      double tt = (xmins[i].first - xmins[j].first) / (xmins[i].second - xmins[j].second);
      if (tt < 0.000001) t.push_back(-tt);
    }
  for (int i = 0; i < ymins.size(); i++)
    for (int j = i + 1; j < ymins.size(); j++) {
      double tt = (ymins[i].first - ymins[j].first) / (ymins[i].second - ymins[j].second);
      if (tt < 0.000001) t.push_back(-tt);
    }
  sort(t.begin(), t.end());
  for (int i = 1; i < t.size(); i++) {
    double t1 = t[i - 1];
    double t2 = t[i];
    double tt = (t1 + t2) / 2;

    double xmin = (double) xmins[0].first + xmins[0].second * tt;
    auto xmi = xmins[0];
    double ymin = (double) ymins[0].first + ymins[0].second * tt;
    auto ymi = ymins[0];
    double xmax = (double) xmaxs[0].first + xmaxs[0].second * tt;
    auto xma = xmaxs[0];
    double ymax = (double) ymaxs[0].first + ymaxs[0].second * tt;
    auto yma = ymaxs[0];
    for (int j = 1; j < xmins.size(); j++) {
      if (xmin > xmins[j].first + xmins[j].second * tt) {
        xmin = xmins[j].first + xmins[j].second * tt;
        xmi = xmins[j];
      }
    }
    for (int j = 1; j < ymins.size(); j++) {
      if (ymin > ymins[j].first + ymins[j].second * tt) {
        ymin = ymins[j].first + ymins[j].second * tt;
        ymi = ymins[j];
      }
    }
    for (int j = 1; j < xmaxs.size(); j++) {
      if (xmax < xmaxs[j].first + xmaxs[j].second * tt) {
        xmax = xmaxs[j].first + xmaxs[j].second * tt;
        xma = xmaxs[j];
      }
    }
    for (int j = 1; j < ymaxs.size(); j++) {
      if (ymax < ymaxs[j].first + ymaxs[j].second * tt) {
        ymax = ymaxs[j].first + ymaxs[j].second * tt;
        yma = ymaxs[j];
      }
    }
    double temp = (xmax - xmin) * (ymax - ymin);
    pair<double, double> x(xma.first - xmi.first, xma.second - xmi.second);
    pair<double, double> y(yma.first - ymi.first, yma.second - ymi.second);
    for (int k = 0; k < 50; k++) {
      double tm = (t1 + t2) / 2;
      if (f(x, (tm + t1) / 2) * f(y, (tm + t1) / 2) > f(x, (tm + t2) / 2) * f(y, (tm + t2) / 2)) {
        t1 = tm;
      } else {
        t2 = tm;
      }
    }
    temp = min(temp, f(x, t1) * f(y, t1));

    if (ans < -0.5) ans = temp;
    else
      ans = min(ans, temp);
  }

  printf("%.9lf\n", ans);

  return 0;
}
