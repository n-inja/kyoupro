#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, m;
vector<vector<pair<int, ll>>> p, inv;
vector<ll> cost;
vector<bool> used;

bool ok = true;
int d = 0;

void dfs(int i, ll c) {
  if (cost[i] >= c || !used[i]) {
    return;
  }
  d++;
  cost[i] = max(cost[i], c);
  if (d > 3 * n) {
    ok = false;
    return;
  }
  for (auto &pr: p[i]) {
    dfs(pr.first, c + pr.second);
  }
}

void dfs2(int i) {
  if (used[i]) return;
  used[i] = true;
  for (auto &j : inv[i]) {
    dfs2(j.first);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  ll INF = 1LL << 50;
  cost.resize(n, -INF);
  inv.resize(n);
  used.resize(n);
  p.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    p[a].emplace_back(b, c);
    inv[b].emplace_back(a, c);
  }
  dfs2(n - 1);

  dfs(0, 0);
  if (ok) {
    cout << cost[n - 1] << endl;
  } else {
    cout << "inf" << endl;
  }

  return 0;
}
