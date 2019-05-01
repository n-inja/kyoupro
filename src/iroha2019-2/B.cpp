#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

double eps = 0.0000001;
using p2 = complex<double>;
// x: real
// y: imag

double det(p2 v1, p2 v2) {
  return v1.real() * v2.imag() - v1.imag() * v2.real();
}
double dot(p2 v1, p2 v2) {
  return v1.real() * v2.real() + v1.imag() * v2.imag();
}
bool same(double x, double y) { return fabs(x - y) < eps; }
double dist2(p2 l1, p2 l2) { return dot(l1 - l2, l1 - l2); }

auto p2comp = [](const p2 &l, const p2 &r) {
  if (fabs(l.real() - r.real()) > eps)
    return l.real() < r.real();
  return l.imag() < r.imag();
};
struct Line {
  p2 st, ed;
  Line(p2 st, p2 ed) : st(st), ed(ed) {}
  Line(double x1, double y1, double x2, double y2)
      : st(p2(x1, y1)), ed(p2(x2, y2)) {}
  Line(p2 st, double x, double y) : st(st), ed(p2(x, y)) {}
  Line(double x, double y, p2 ed) : st(p2(x, y)), ed(ed) {}
  double dist() { return sqrt(dist2(st, ed)); }
  bool isPalla(Line l) { return fabs(det(ed - st, l.ed - l.st)) < eps; }
  double x() { return ed.real() - st.real(); }
  double y() { return ed.imag() - st.imag(); }
};

// l1.st + (l1.st - l1.ed) * r.first = l2.st + (l2.st - l2.ed) * r.second
// 方程式を満たす(r.first, r.second)を返す
// l1.isPalla(l2) => (nan, nan)
pair<double, double> interP(Line l1, Line l2) {
  double a = l1.x();
  double b = -l2.x();
  double c = l1.y();
  double d = -l2.y();
  double inv = 1. / (a * d - c * b);
  double e1 = -l1.st.real() + l2.st.real();
  double e2 = -l1.st.imag() + l2.st.imag();
  return make_pair((d * e1 - b * e2) * inv, (-c * e1 + a * e2) * inv);
}

bool intersec(Line l1, Line l2) {
  if (l1.isPalla(l2))
    return false;
  auto r = interP(l1, l2);
  return eps < r.first && r.first < 1. - eps && eps < r.second &&
         r.second < 1. - eps;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  double x, y, a, b, x1, y1, x2, y2;
  cin >> x >> y >> a >> b >> x1 >> y1 >> x2 >> y2;
  Line l1(0, a, x, b), l2(x1, y1, x2, y2);
  if (intersec(l1, l2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
