#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
template <typename T> class tRMQ {
  vector<T> data;
  T unit;

public:
  static const long long INF = 100000000000;
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

ll n, m, q;
vector<vector<int>> skip;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  vll p(n), pinv(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    pinv[p[i] - 1] = i;
  }
  vll a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    b[i] = pinv[a[i] - 1];
  }
  vector<pair<int, int>> ps(q);
  for (int i = 0; i < q; i++) {
    cin >> ps[i].first >> ps[i].second;
    ps[i].first--;
  }
  skip.resize(m);
  vector<int> bef(n);
  for (int i = 0; i < n; i++)
    bef[i] = m;
  for (int i = m - 1; i >= 0; i--) {
    if (bef[(b[i] + 1) % n] < m) {
      skip[i].push_back(bef[(b[i] + 1) % n]);
    }
    bef[b[i]] = i;
  }
  for (int k = 1; k < 30; k++) {
    for (int i = 0; i < m; i++) {
      if (skip[i].size() < k)
        continue;
      if (skip[skip[i][k - 1]].size() < k)
        continue;
      skip[i].push_back(skip[skip[i][k - 1]][k - 1]);
    }
  }
  tRMQ<ll> rmq(m, 10000000000000LL, [](ll l, ll r) { return min(l, r); });
  for (int i = 0; i < m; i++) {
    ll len = n - 1;
    ll now = i, k = 0;
    while (len > 0) {
      if (len & 1) {
        if (skip[now].size() <= k) {
          now = 10000000000000LL;
          break;
        }
        now = skip[now][k];
      }
      k++;
      len >>= 1;
    }
    rmq.update(i, now);
  }
  for (int i = 0; i < q; i++) {
    if (rmq.query(ps[i].first, ps[i].second) < ps[i].second) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << endl;

  return 0;
}
