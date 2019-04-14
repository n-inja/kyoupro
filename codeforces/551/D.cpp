#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int n;
vi v, p;
vvi inv;
int k = 0;

ll dfs(int i, ll m) {
  if (inv[i].size() == 0) {
    if (m < 0)
      return 0;
    else
      return 1;
  }
  vll w;
  for (auto &j : inv[i]) {
    w.push_back(dfs(j, m));
  }
  if (v[i] == 0) {
    ll ret = 0;
    for (auto &a : w)
      ret += a;
    return ret;
  } else {
    sort(w.begin(), w.end());
    return w[0];
  }
}

bool f(ll m) {
  ll c = dfs(0, m);
  ll d = k - m + 1;
  return c <= d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  v.resize(n);
  p.resize(n);
  inv.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    inv[p[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (inv[i].size() == 0)
      k++;
  }
  ll l = 0, r = k + 1;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;

  return 0;
}
