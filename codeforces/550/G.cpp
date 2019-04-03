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

tRMQ<ll> minrmq(int n) {
  return tRMQ<ll>(n, 10000000000000000LL, [](ll r, ll l) { return min(l, r); });
}
tRMQ<ll> maxrmq(int n) {
  return tRMQ<ll>(n, -10000000000000000LL,
                  [](ll r, ll l) { return max(l, r); });
}
tRMQ<ll> sumrmq(int n) {
  return tRMQ<ll>(n, 0, [](ll l, ll r) { return l + r; });
}

bool solve(vector<ll> a, bool mode) {
  int n = a.size();
  vector<pair<int, ll>> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = make_pair(i, a[i]);
  }
  sort(b.begin(), b.end(), [](const pair<int, ll> &l, const pair<int, ll> &r) {
    if (l.second == r.second)
      return l.first > r.first;
    return l.second < r.second;
  });
  tRMQ<pair<int, ll>> q(n, make_pair(-1, 0),
                        [](pair<int, ll> l, pair<int, ll> r) {
                          if (l.second == r.second) {
                            if (l.first < r.first)
                              return l;
                            else
                              return r;
                          }
                          if (l.second > r.second)
                            return l;
                          else
                            return r;
                        });
  vi bef(n);
  for (int i = 0; i < n; i++) {
    bef[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    auto p = q.query(0, b[i].first);
    q.update(b[i].first, make_pair(b[i].first, p.second + 1));
    bef[b[i].first] = p.first;
  }
  int id = 0, maxnum = 0;
  for (int i = 0; i < n; i++) {
    auto p = q.query(i, i + 1);
    if (p.second >= maxnum) {
      maxnum = p.second;
      id = i;
    }
  }

  vector<bool> used(n);
  while (id >= 0) {
    used[id] = true;
    id = bef[id];
  }
  ll now = 3000000;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      if (now <= a[i]) {
        ok = false;
      } else {
        now = a[i];
      }
    }
  }
  if (ok) {
    cout << "YES" << endl;
    if (!mode) {
      cout << !used[0];
      for (int i = 1; i < n; i++)
        cout << " " << !used[i];
      cout << endl;
    } else {
      cout << used[n - 1];
      for (int i = n - 2; i >= 0; i--)
        cout << " " << used[i];
      cout << endl;
    }
    return true;

  } else {
    return false;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (!solve(a, false)) {
    reverse(a.begin(), a.end());
    if (!solve(a, true)) {
      cout << "NO" << endl;
    }
  }
  return 0;
}