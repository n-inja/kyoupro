#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll P = 1000000007;

template <typename T> class RMQ {
  vector<T> data;
  T unit;

public:
  static const long long INF = 100000000000;
  int n;
  function<T(const T &, const T &)> f;
  RMQ(int _, T u, function<T(T, T)> bi) {
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
  int n;
  ll a, b;
  cin >> n >> a >> b;
  vll v(n + 1);
  v[0] = -(1LL << 62);
  for (int i = 0; i < n; i++)
    cin >> v[i + 1];
  for (int i = 2; i <= n; i++)
    if (v[i] - v[i - 2] < min(a, b)) {
      cout << "0" << endl;
      return 0;
    }
  if (a > b)
    swap(a, b);
  RMQ<ll> rmq(n + 1, 0,
              [](const ll &l, const ll &r) { return (l + r) % 1000000007; });
  rmq.update(0, 1);
  rmq.update(1, 1);
  int p = 0;
  for (int i = 2; i <= n; i++) {
    auto j = upper_bound(v.begin(), v.begin() + i, v[i] - b) - v.begin();
    if (j > p)
      rmq.update(i, rmq.query(p, j));
    if (v[i] - v[i - 1] < a) {
      p = i - 1;
    }
  }
  cout << rmq.query(p, n + 1) << endl;
  return 0;
}
