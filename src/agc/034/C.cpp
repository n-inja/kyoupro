#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll n, x;
struct N {
  ll b, l, u;
};
vector<N> ns;
vector<ll> ss;
ll sub = 0;

bool operator<(const N &l, const N &r) {
  return l.b * l.l + (x - l.b) * l.u > r.b * r.l + (x - r.b) * r.u;
}

bool f(ll m) {
  ll q = m / x;
  ll k = m - q * x;

  for (int i = 0; i < n; i++) {
    ll sum = 0;
    if (i < q) {
      sum = ss[q + 1] - (ns[i].b * ns[i].l + (x - ns[i].b) * ns[i].u);
    } else {
      sum = ss[q];
    }

    if (k >= ns[i].b) {
      sum += ns[i].l * ns[i].b + (k - ns[i].b) * ns[i].u;
    } else {
      sum += ns[i].l * k;
    }

    if (sum >= sub) return true;
  }

  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> x;
  ns.resize(n);
  ss.resize(n + 1);
  for (int i = 0; i < n; i++) cin >> ns[i].b >> ns[i].l >> ns[i].u;
  sort(ns.begin(), ns.end());
  for (int i = 0; i < n; i++) sub += ns[i].b * ns[i].l;
  for (int i = 0; i < n; i++) ss[i + 1] = ss[i] + ns[i].b * ns[i].l + (x - ns[i].b) * ns[i].u;
  ll l = 0, r = x * n;
  if (f(0)) {
    cout << 0 << endl;
    return 0;
  }
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;

  return 0;
}
