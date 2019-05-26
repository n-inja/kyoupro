#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  ll a, b;
  int id;
};

bool operator<(const N &l, const N &r) {
  return (l.a + r.b - 1) * l.b > (r.a + l.b - 1) * r.b;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> ns(n);
  for (int i = 0; i < n; i++) {
    cin >> ns[i].a >> ns[i].b;
    ns[i].id = i;
  }
  sort(ns.begin(), ns.end());

  bool ok = true;
  for (int i = 1; i < n; i++) {
    ll l = (ns[i].a + ns[0].b - 1) / ns[0].b;
    ll r = (ns[0].a + ns[i].b - 1) / ns[i].b;
    if (r <= l) ok = false;
  }
  if (ok) {
    cout << ns[0].id + 1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
