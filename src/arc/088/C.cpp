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
  string s;
  cin >> s;
  map<int, vector<int>> mp;
  map<int, pair<int, int>> ps;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    mp[s[i] - 'a'].push_back(i);
  }
  int c = 0;
  for (auto &v : mp) {
    if (v.second.size() % 2) c++;
    ps[v.first] = make_pair(0, v.second.size() - 1);
  }
  if (c > 1) {
    cout << -1 << endl;
    return 0;
  }
  auto r = sumrmq(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    r.update(i, 1);
  }
  int offset = 0;
  for (int i = 0; i < n; i++) {
    while (r.query(i + offset, i + offset + 1) == 0 && i + offset < n) {
      offset++;
    }
    if (i + offset >= n) break;
    if (ps[s[i + offset] - 'a'].first == ps[s[i + offset] - 'a'].second) {
      continue;
    }
    r.update(mp[s[i + offset] - 'a'][ps[s[i + offset] - 'a'].second], 0);
    r.update(mp[s[i + offset] - 'a'][ps[s[i + offset] - 'a'].first], 0);
    ans += r.query(0, mp[s[i + offset] - 'a'][ps[s[i + offset] - 'a'].first]) +
           r.query(mp[s[i + offset] - 'a'][ps[s[i + offset] - 'a'].second], n);
    ps[s[i + offset] - 'a'].first++;
    ps[s[i + offset] - 'a'].second--;
  }

  cout << ans << endl;
  return 0;
}
