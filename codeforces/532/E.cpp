#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct M {
  int f, t, c;
};

int n, m;
vvi p, pinv;
vector<M> ps;
vector<int> used;
vector<int> num, vs;
int id = 0;

void dfs(int i) {
  if (used[i])
    return;
  used[i] = true;
  for (auto &j : pinv[i])
    dfs(j);
  vs.push_back(i);
  return;
}

bool f(ll ok, bool mode) {
  pinv.clear();
  used.clear();
  num.clear();
  p.clear();
  pinv.resize(n);
  used.resize(n);
  num.resize(n);
  p.resize(n);
  vs.clear();
  id = 0;
  for (int i = 0; i < m; i++)
    if (ps[i].c > ok) {
      pinv[ps[i].t - 1].push_back(ps[i].f - 1);
      p[ps[i].f - 1].push_back(ps[i].t - 1);
    }

  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;
    dfs(i);
  }
  reverse(vs.begin(), vs.end());
  for (auto &i : vs) {
    num[i] = id++;
  }
  vi rev;
  for (int i = 0; i < m; i++) {
    if (ps[i].c <= ok && num[ps[i].f - 1] < num[ps[i].t - 1]) {
      rev.push_back(i + 1);
    }
    if (ps[i].c > ok && num[ps[i].f - 1] < num[ps[i].t - 1]) {
      return false;
    }
  }
  if (!mode)
    return true;
  cout << ok << " " << rev.size() << endl;
  if (rev.size()) {
    cout << rev[0];
    for (int i = 1; i < rev.size(); i++)
      cout << " " << rev[i];
  }
  cout << endl;
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  ps.resize(m);
  for (int i = 0; i < m; i++)
    cin >> ps[i].f >> ps[i].t >> ps[i].c;
  ll l = 0, r = 1000000000;

  if (f(l, false)) {
    f(l, true);
    return 0;
  }
  while (r - l > 1) {
    ll mm = (l + r) / 2;
    if (f(mm, false)) {
      r = mm;
    } else {
      l = mm;
    }
  }
  f(r, true);
  return 0;
}
