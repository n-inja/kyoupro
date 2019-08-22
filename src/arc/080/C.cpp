#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;

template<typename T>
class tRMQ {
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

int INF = 1 << 30;

struct N {
  int l, r;
  int v;
};

bool operator<(const N &l, const N &r) {
  return l.v > r.v;
}

struct M {
  int l, r, id;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<int> ans;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  tRMQ<pii> r(n, make_pair(INF, -1), [](pii l, pii r) {
    if (l.second % 2 == 1) return r;
    if (r.second % 2 == 1) return l;
    if (l.first < r.first) return l;
    else return r;
  });
  tRMQ<pii> r2(n, make_pair(INF, -1), [](pii l, pii r) {
    if (l.second % 2 == 0) return r;
    if (r.second % 2 == 0) return l;
    if (l.first < r.first) return l;
    else return r;
  });
  for (int i = 0; i < n; i++) {
    r.update(i, make_pair(v[i], i));
    r2.update(i, make_pair(v[i], i));
  }
  priority_queue<N> q;
  q.push(N{0, n, r.query(0, n).first});
  while (q.size()) {
    N now = q.top();
    q.pop();
    bool frip = now.l % 2 == 1;
    if (frip) {
      auto pr = r2.query(now.l, now.r);
      ans.push_back(pr.first);
      auto pr2 = r.query(pr.second + 1, now.r);
      ans.push_back(pr2.first);
      if (now.l < pr.second)
        q.push(N{now.l, pr.second, r2.query(now.l, pr.second).first});
      if (pr.second + 1 < pr2.second)
        q.push(N{pr.second + 1, pr2.second, r.query(pr.second + 1, pr2.second).first});
      if (pr2.second + 1 < now.r)
        q.push(N{pr2.second + 1, now.r, r2.query(pr2.second + 1, now.r).first});
    } else {
      auto pr = r.query(now.l, now.r);
      ans.push_back(pr.first);
      auto pr2 = r2.query(pr.second + 1, now.r);
      ans.push_back(pr2.first);
      if (now.l < pr.second)
        q.push(N{now.l, pr.second, r.query(now.l, pr.second).first});
      if (pr.second + 1 < pr2.second)
        q.push(N{pr.second + 1, pr2.second, r2.query(pr.second + 1, pr2.second).first});
      if (pr2.second + 1 < now.r)
        q.push(N{pr2.second + 1, now.r, r.query(pr2.second + 1, now.r).first});
    }
  }
  cout << ans[0];
  for (int i = 1; i < n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
