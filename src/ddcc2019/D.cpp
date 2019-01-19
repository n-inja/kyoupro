#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
using vvui = vector<vector<unsigned int>>;
struct N {
  vvui val;
  bool isUnit;
};

template <typename T> class RMQ {
  vector<T> data;
  T unit;

public:
  static const long long INF = 100000000000;
  int n;
  function<T(const T &, const T &)> f;
  RMQ(string s, T u, function<T(T, T)> bi) {
    unit = u;
    f = bi;
    n = 1;
    while (n < s.size()) {
      n <<= 1;
    }
    data.resize(n * 4);
    N a, b, c, d, e;
    a.isUnit = false;
    b.isUnit = false;
    c.isUnit = false;
    d.isUnit = false;
    e.isUnit = false;
    vvui I(6);
    for (int i = 0; i < 6; i++) {
      I[i].resize(6);
      I[i][i] = 1;
    }
    a.val = I;
    a.val[0][1] = 1;
    b.val = I;
    b.val[1][2] = 1;
    c.val = I;
    c.val[2][3] = 1;
    d.val = I;
    d.val[3][4] = 1;
    e.val = I;
    e.val[4][5] = 1;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'D')
        data[i + n - 1] = a;
      else if (s[i] == 'I')
        data[i + n - 1] = b;
      else if (s[i] == 'S')
        data[i + n - 1] = c;
      else if (s[i] == 'C')
        data[i + n - 1] = d;
      else if (s[i] == 'O')
        data[i + n - 1] = e;
      else
        data[i + n - 1] = unit;
    }
    for (int i = s.size() + n - 1; i < 4 * n; i++) {
      data[i] = unit;
    }
    for (int i = n - 2; i >= 0; i--) {
      data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  void update(int index, T val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  // [a, b)
  T query(int a, int b, int k, int l, int r) {
    if (a < 0 || r <= a || b <= l)
      return unit;
    if (a <= l && r <= b)
      return data[k];
    else
      return f(query(a, b, k * 2 + 1, l, (l + r) / 2),
               query(a, b, k * 2 + 2, (r + l) / 2, r));
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int q;
  cin >> q;
  N unit;
  unit.isUnit = true;

  RMQ<N> rmq(s, unit, [](const N &l, const N &r) {
    if (l.isUnit)
      return r;
    if (r.isUnit)
      return l;
    N ret;
    ret.isUnit = false;
    ret.val.resize(6);
    for (int i = 0; i < 6; i++)
      ret.val[i].resize(6);
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
        for (int k = 0; k < 6; k++)
          ret.val[i][j] += l.val[i][k] * r.val[k][j];
    return ret;
  });

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    auto ret = rmq.query(l - 1, r);
    if (ret.isUnit)
      cout << 0 << endl;
    else
      cout << ret.val[0][5] << endl;
  }
  return 0;
}
