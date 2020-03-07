#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n;
vector<pair<ll, ll>> ps;
map<ll, int> mp;
ll P = 998244353;

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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  ps.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second;
  }
  sort(ps.begin(), ps.end());
  for (int i = 0; i < n; i++) {
    mp[ps[i].first] = 0;
    mp[ps[i].first + ps[i].second] = 0;
  }
  int c = 0;
  vector<ll> inv;
  for (auto &it  : mp) {
    it.second = c++;
    inv.push_back(it.first);
  }
  inv.push_back(10000000000000LL);
  tRMQ<ll> r = maxrmq(c);
  for (int i = 0; i < c; i++)r.update(i, i);
  for (int i = n - 1; i >= 0; i--) {
    r.update(mp[ps[i].first], r.query(mp[ps[i].first], mp[ps[i].first + ps[i].second]));
  }
  ll memo[201010] = {0};
  memo[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    auto p = make_pair(inv[r.query(mp[ps[i].first], mp[ps[i].first] + 1)] + 1, 0LL);
    auto it = lower_bound(ps.begin(), ps.end(), p);
    memo[i] = (memo[i + 1] + memo[it - ps.begin()]) % P;
  }
  cout << memo[0] << endl;

  return 0;
}
