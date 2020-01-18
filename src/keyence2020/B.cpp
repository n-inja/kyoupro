#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  ll x, l;
};

bool operator<(const N &l, const N &r) {
  return l.x + l.l < r.x + r.l;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> ns(n);
  for (int i = 0; i < n; i++) cin >> ns[i].x >> ns[i].l;
  sort(ns.begin(), ns.end());
  ll ans = 0;
  ll now = -10000000000;
  for (int i = 0; i < n; i++) {
    if (ns[i].x - ns[i].l >= now) {
      now = ns[i].x + ns[i].l;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
