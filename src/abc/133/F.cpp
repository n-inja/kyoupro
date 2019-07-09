#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  N(int i, int c, int d) : i(i), c(c), d(d) {}

  int i, c, d;
};

int n, q;
vector<vector<N>> p;

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

tRMQ<ll> minrmq(int n) {
  return tRMQ<ll>(n, 10000000, [](int r, int l) { return min(l, r); });
}

vector<ll> to(101010), toinv(101010), inx(202020);
vector<ll> depth(101010);
vector<map<ll, pair<ll, ll>>> request(101010);

ll c = 0, cc = 0;
auto r = minrmq(202020);

void dfs(int i, int from, ll dep) {
  depth[i] = dep;
  to[i] = c++;
  inx[i] = cc;
  r.update(cc++, to[i]);
  for (auto &j : p[i]) {
    if (j.i == from) continue;
    dfs(j.i, i, dep + j.d);
    r.update(cc++, to[i]);
  }
}

struct Query {
  ll x, y, a, b;
};

void dfs2(int i, int from, vector<pair<ll, ll>> &v) {
  for (auto &j : request[i]) {
    j.second = v[j.first];
  }
  for (auto &j : p[i]) {
    if (from == j.i) continue;
    v[j.c].first += j.d;
    v[j.c].second += 1;
    dfs2(j.i, i, v);
    v[j.c].first -= j.d;
    v[j.c].second -= 1;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> q;
  p.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    p[a].emplace_back(b, c, d);
    p[b].emplace_back(a, c, d);
  }
  dfs(0, -1, 0);
  for (int i = 0; i < n; i++) toinv[to[i]] = i;

  vector<Query> qs(q);
  for (int i = 0; i < q; i++) {
    cin >> qs[i].x >> qs[i].y >> qs[i].a >> qs[i].b;
    qs[i].a--;
    qs[i].b--;
    auto lca = toinv[r.query(min(inx[qs[i].a], inx[qs[i].b]), max(inx[qs[i].a], inx[qs[i].b]) + 1)];
    request[qs[i].a][qs[i].x] = make_pair(0, 0);
    request[qs[i].b][qs[i].x] = make_pair(0, 0);
    request[lca][qs[i].x] = make_pair(0, 0);
  }

  vector<pair<ll, ll>> v(101010);
  dfs2(0, -1, v);

  for (int i = 0; i < q; i++) {

    auto lca = toinv[r.query(min(inx[qs[i].a], inx[qs[i].b]), max(inx[qs[i].a], inx[qs[i].b]) + 1)];

    ll a_d = depth[qs[i].a] - depth[lca];
    ll b_d = depth[qs[i].b] - depth[lca];
    ll a_cd = request[qs[i].a][qs[i].x].first - request[lca][qs[i].x].first;
    ll b_cd = request[qs[i].b][qs[i].x].first - request[lca][qs[i].x].first;
    ll a_cc = request[qs[i].a][qs[i].x].second - request[lca][qs[i].x].second;
    ll b_cc = request[qs[i].b][qs[i].x].second - request[lca][qs[i].x].second;

    cout << a_d + b_d - (a_cd + b_cd) + (a_cc + b_cc) * qs[i].y << endl;
  }

  return 0;
}
