#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

template <typename T> class DST {
public:
  int n;
  function<T(T, T)> f;
  vector<T> v;
  vector<pair<vector<T>, vector<T>>> table[32];
  DST(vector<T> &_v, function<T(T, T)> f) : v(_v), f(f) {
    n = 1;
    while (n < v.size()) {
      n <<= 1;
    }
    v.resize(n);
    int m = n >> 1;
    for (int k = 0; m; k++, m >>= 1) {
      table[k].resize(m);
      int kshift = 1 << k;
      int piv = kshift;
      for (int i = 0; i < m; i++) {
        table[k][i].first.resize(kshift);
        table[k][i].second.resize(kshift);
        table[k][i].first[0] = v[piv - 1];
        table[k][i].second[0] = v[piv];
        for (int j = 1; j < kshift; j++) {
          table[k][i].first[j] = f(table[k][i].first[j - 1], v[piv - 1 - j]);
          table[k][i].second[j] = f(table[k][i].second[j - 1], v[piv + j]);
        }
        piv += 2 << k;
      }
    }
  }
  T query(int l, int r) {
    if (r - l <= 1)
      return v[l];
    r--;
    int k = 31 - __builtin_clz(l ^ r);
    int index = l >> (k + 1);
    int piv = index * (2 << k) + (1 << k);
    return f(table[k][index].first[piv - l - 1],
             table[k][index].second[r - piv]);
  }
};

ll n, k;
ll f(DST<ll> &q, ll k) {
  ll ret = 0;
  for (int i = 0; i < n; i++) {
    ll l = i, r = n;
    if (q.query(i, n) < k) {
      continue;
    }
    while (r - l > 1) {
      ll m = (l + r) / 2;
      if (q.query(i, m) >= k) {
        r = m;
      } else {
        l = m;
      }
    }
    ret += n - l;
  }
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  vll a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  DST<ll> q(a, [](ll l, ll r) { return l | r; });

  ll l = 0, r = (1LL << 60);
  while (r - l > 1) {
    ll m = (l + r) / 2;
    ll a = f(q, m);
    if (a >= k) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
