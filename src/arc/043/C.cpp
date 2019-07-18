#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


template<typename T>
class tRMQ {
  vector<T> data;
  T unit;

public:
  int n;
  function<T(const T &, const T &)> f;

  tRMQ(int _, T u, function<T(T, T)> bi) {
    unit = u;
    f = bi;
    n = 1;
    while (n < _) {
      n <<= 1;
    }
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = unit;
  }

  tRMQ(vector<T> &v, T u, function<T(T, T)> bi) {
    unit = u;
    f = bi;
    n = 1;
    while (n < v.size())
      n <<= 1;
    data.resize(n * 4, u);
    for (int i = 0; i < v.size(); i++) {
      data[n + i - 1] = v[i];
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n), ainv(n), cinv(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    ainv[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) c[i] = ainv[b[i]];
  tRMQ<ll> q(n, 0, [](ll l, ll r) {
    return l + r;
  });
  ll cross = 0;
  for (int i = n - 1; i >= 0; i--) {
    cross += q.query(0, c[i]);
    q.update(c[i], 1);
  }
  if (cross % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) cinv[c[i]] = i;

  cross >>= 1;
  tRMQ<ll> sum(n, 0, [](ll l, ll r) {
    return l + r;
  });

  for (int i = 0; i < n && cross; i++) {
    int nowpos = cinv[i] - sum.query(0, cinv[i]);
    if (nowpos < cross) {
      cross -= nowpos;
      sum.update(cinv[i], 1);
    } else {
      vector<int> d, dinv(n);
      for (int j = 0; j < i; j++) d.push_back(j);
      for (int j = 0; j < n; j++) {
        if (c[j] >= i) d.push_back(c[j]);
      }
      for (int j = 0; j < n; j++) dinv[d[j]] = j;
      for (int j = dinv[i]; j > i && cross; j--) {
        swap(d[j - 1], d[j]);
        cross--;
      }
      cout << a[d[0]] + 1;
      for (int j = 1; j < n; j++) cout << " " << a[d[j]] + 1;
      cout << endl;
      return 0;
    }
  }

  return 1;
}
