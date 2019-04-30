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

struct Poly {
  vector<p2> ps;
  Poly(vector<p2> ps) : ps(ps) {}
  bool include(p2 p) {
    vector<double> b;
    for (int i = 0; i < ps.size(); i++) {
      b.push_back(det(p, ps[i] - ps[(i + 1) % ps.size()]));
    }
    bool allPlus = true, allMinus = true;
    for (auto &x : b) {
      if (x > eps)
        allMinus = false;
      if (x < -eps)
        allPlus = false;
    }
    return allMinus || allPlus;
  }
  bool intersecl(Line l) {
    for (int i = 0; i < ps.size(); i++) {
      if (intersec(l, Line(ps[i], ps[(i + 1) % ps.size()])))
        return true;
    }
    return false;
  }
};

struct Circle {
  p2 p;
  double r;
  Circle(p2 p, double r) : p(p), r(r) {}
  bool include(p2 l) { return dist2(p, l) < r * r + eps; }

  // 円同士の交点
  // 存在すれば2つ
  vector<p2> intersec(Circle c) {
    p2 diff = c.p - p;
    double dist = dot(diff, diff);
    double a = (dist + r * r - c.r * c.r) / 2.;
    double D = dist * r * r - a * a;
    if (D < eps)
      return vector<p2>();
    double Dsqrt = sqrt(D);
    vector<p2> ps;
    ps.emplace_back((a * diff.real() + diff.imag() * Dsqrt) / dist + p.real(),
                    (a * diff.imag() - diff.real() * Dsqrt) / dist + p.imag());
    ps.emplace_back((a * diff.real() - diff.imag() * Dsqrt) / dist + p.real(),
                    (a * diff.imag() + diff.real() * Dsqrt) / dist + p.imag());
    return ps;
  }
};

// 逆時計回り
struct ConX {
  vector<p2> ps;
  // graham scan
  // ref: プログラミングコンテストチャレンジブック p233
  ConX(vector<p2> v) {
    sort(v.begin(), v.end(), p2comp);

    int k = 0, n = v.size();
    ps.resize(n * 2);
    for (int i = 0; i < n; i++) {
      while (k > 1 && det(ps[k - 1] - ps[k - 2], v[i] - ps[k - 1]) < eps)
        k--;
      ps[k++] = v[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
      while (k > t && det(ps[k - 1] - ps[k - 2], v[i] - ps[k - 1]) < eps)
        k--;
      ps[k++] = v[i];
    }
    ps.resize(k - 1);
  }
  size_t size() { return ps.size(); }
};

int n;
vector<double> rs;
vector<p2> ps;
vector<Circle> cs;

bool f(double l) {
  cs.clear();
  for (int i = 0; i < n; i++) {
    double rr = rs[i] * rs[i] - l * l;
    if (rr < eps)
      return false;
    cs.emplace_back(ps[i], sqrt(rr));
  }
  vector<p2> may;
  for (int i = 0; i < n; i++) {
    may.push_back(cs[i].p);
    for (int j = i + 1; j < n; j++) {
      auto v = cs[i].intersec(cs[j]);
      if (v.size() == 0)
        continue;
      may.push_back(v[0]);
      may.push_back(v[1]);
    }
  }
  for (auto &p : may) {
    bool ok = true;
    for (auto &c : cs) {
      if (!c.include(p)) {
        ok = false;
        break;
      }
    }
    if (ok)
      return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  return 0;
}
