#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  string s;
  int p, i;
};

bool operator<(const N &l, const N &r) {
  if (l.s == r.s) {
    return l.p > r.p;
  }
  return l.s < r.s;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> ns(n);
  for (int i = 0; i < n; i++) {
    cin >> ns[i].s >> ns[i].p;
    ns[i].i = i;
  }
  sort(ns.begin(), ns.end());
  for (auto &v : ns) {
    cout << v.i + 1 << endl;
  }
  return 0;
}
