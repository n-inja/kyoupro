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
    data.resize(n * 2 + 1);
    for (int i = 0; i < n + 1; i++) {
      if (i < v.size())
        data[i + n] = v[i];
      else
        data[i + n] = u;
    }
    for (int i = n - 1; i >= 0; i--) {
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
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  map<ll, int> mp;
  int c = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    if (mp.find(a[i].first) == mp.end())
      mp[a[i].first] = 0;
    if (mp.find(a[i].second) == mp.end())
      mp[a[i].second] = 0;
  }
  for (auto &v: mp) v.second = c++;
  for (int i = 0; i < n; i++) {
    a[i].first = mp[a[i].first];
    a[i].second = mp[a[i].second];
  }
  for (int i = 0; i < n; i++)
    if (a[i].first < a[i].second) swap(a[i].first, a[i].second);
  sort(a.begin(), a.end(), [](const pair<ll, ll> &l, const pair<ll, ll> &r) {
    if (l.first == r.first) return l.second > r.second;
    return l.first < r.first;
  });
  auto r = maxrmq(c);
  r.update(0, 0);
  for (int i = 0; i < n; i++) {
    auto v = r.query(0, a[i].second);
    r.update(a[i].second, v + 1);
  }
  cout << r.query(0, c) << endl;

  return 0;
}
